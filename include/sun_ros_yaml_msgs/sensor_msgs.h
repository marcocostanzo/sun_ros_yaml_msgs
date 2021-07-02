#ifndef SUN_ROS_YAML_MSGS_SENSOR_MSGS_H
#define SUN_ROS_YAML_MSGS_SENSOR_MSGS_H

#include "yaml-cpp/yaml.h"
#include "sun_ros_yaml_msgs/std_msgs.h"
#include "sensor_msgs/JointState.h"

namespace YAML
{

  template <>
  struct convert<sensor_msgs::JointState>
  {
    static Node encode(const sensor_msgs::JointState &jointstate)
    {
      Node node;
      node["header"] = jointstate.header;
      node["name"] = jointstate.name;
      node["position"] = jointstate.position;
      node["velocity"] = jointstate.velocity;
      node["effort"] = jointstate.effort;

      return node;
    }

    static bool decode(const Node &node, sensor_msgs::JointState &jointstate)
    {
      jointstate.header = node["header"].as<std_msgs::Header>();
      jointstate.name = node["name"].as<std::vector<std::string>>();
      jointstate.position = node["position"].as<std::vector<double>>();
      jointstate.velocity = node["velocity"].as<std::vector<double>>();
      jointstate.effort = node["effort"].as<std::vector<double>>();
      return true;
    }
  };

} // namespace YAML

#endif