#ifndef SUN_ROS_YAML_MSGS_STD_MSGS_H
#define SUN_ROS_YAML_MSGS_STD_MSGS_H

#include "yaml-cpp/yaml.h"
#include "ros/time.h"
#include "std_msgs/Header.h"


namespace YAML
{
template <>
struct convert<ros::Time>
{
  static Node encode(const ros::Time& t)
  {
    Node node;
    node["sec"] = t.sec;
    node["nsec"] = t.nsec;
    return node;
  }

  static bool decode(const Node& node, ros::Time& t)
  {
    t.nsec = node["nsec"].as<int32_t>();
    t.sec = node["sec"].as<int32_t>();
    return true;
  }
};

template <>
struct convert<ros::Duration>
{
  static Node encode(const ros::Duration& d)
  {
    Node node;
    node["sec"] = d.sec;
    node["nsec"] = d.nsec;
    return node;
  }

  static bool decode(const Node& node, ros::Duration& d)
  {
    d.nsec = node["nsec"].as<int32_t>();
    d.sec = node["sec"].as<int32_t>();
    return true;
  }
};

template <>
struct convert<std_msgs::Header>
{
  static Node encode(const std_msgs::Header& h)
  {
    Node node;
    node["frame_id"] = h.frame_id;
    node["seq"] = h.seq;
    node["stamp"] = h.stamp;
    return node;
  }

  static bool decode(const Node& node, std_msgs::Header& h)
  {
    h.frame_id = node["frame_id"].as<std::string>();
    h.seq = node["seq"].as<uint32_t>();
    h.stamp = node["stamp"].as<ros::Time>();
    return true;
  }
};

}  // namespace YAML

#endif