#ifndef SUN_ROS_YAML_MSGS_GEOMETRY_MSGS_H
#define SUN_ROS_YAML_MSGS_GEOMETRY_MSGS_H

#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"
#include "yaml-cpp/yaml.h"

namespace YAML {

template <> struct convert<geometry_msgs::Vector3> {
  static Node encode(const geometry_msgs::Vector3 &v) {
    Node node;
    node["x"] = v.x;
    node["y"] = v.y;
    node["z"] = v.z;
    return node;
  }

  static bool decode(const Node &node, geometry_msgs::Vector3 &v) {
    v.x = node["x"].as<double>();
    v.y = node["y"].as<double>();
    v.z = node["z"].as<double>();
    return true;
  }
};

template <> struct convert<geometry_msgs::Point> {
  static Node encode(const geometry_msgs::Point &point) {
    Node node;
    node["x"] = point.x;
    node["y"] = point.y;
    node["z"] = point.z;
    return node;
  }

  static bool decode(const Node &node, geometry_msgs::Point &point) {
    if (node.IsMap()) {
      point.x = node["x"].as<double>();
      point.y = node["y"].as<double>();
      point.z = node["z"].as<double>();
    } else {
      point.x = node[0].as<double>();
      point.y = node[1].as<double>();
      point.z = node[2].as<double>();
    }
    return true;
  }
};

template <> struct convert<geometry_msgs::Quaternion> {
  static Node encode(const geometry_msgs::Quaternion &res) {
    Node node;
    node["x"] = res.x;
    node["y"] = res.y;
    node["z"] = res.z;
    node["w"] = res.w;
    return node;
  }

  static bool decode(const Node &node, geometry_msgs::Quaternion &res) {
    res.x = node["x"].as<double>();
    res.y = node["y"].as<double>();
    res.z = node["z"].as<double>();
    res.w = node["w"].as<double>();
    return true;
  }
};

template <> struct convert<geometry_msgs::Pose> {
  static Node encode(const geometry_msgs::Pose &pos) {
    Node node;
    node["position"] = pos.position;
    node["orientation"] = pos.orientation;
    return node;
  }

  static bool decode(const Node &node, geometry_msgs::Pose &pos) {
    pos.position = node["position"].as<geometry_msgs::Point>();
    pos.orientation = node["orientation"].as<geometry_msgs::Quaternion>();
    return true;
  }
};

template <> struct convert<geometry_msgs::Twist> {
  static Node encode(const geometry_msgs::Twist &twist) {
    Node node;
    node["linear"] = twist.linear;
    node["angular"] = twist.angular;
    return node;
  }

  static bool decode(const Node &node, geometry_msgs::Twist &twist) {
    twist.linear = node["linear"].as<geometry_msgs::Vector3>();
    twist.angular = node["angular"].as<geometry_msgs::Vector3>();
    return true;
  }
};

} // namespace YAML

#endif