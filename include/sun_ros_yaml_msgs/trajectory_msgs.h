#ifndef SUN_ROS_YAML_MSGS_TRAJECTORY_MSGS_H
#define SUN_ROS_YAML_MSGS_TRAJECTORY_MSGS_H

#include "yaml-cpp/yaml.h"
#include "sun_ros_yaml_msgs/std_msgs.h"
#include "trajectory_msgs/JointTrajectoryPoint.h"
#include "trajectory_msgs/JointTrajectory.h"

namespace YAML
{

template <>
struct convert<trajectory_msgs::JointTrajectoryPoint>
{
  static Node encode(const trajectory_msgs::JointTrajectoryPoint& trjp)
  {
    Node node;

    node["accelerations"] = trjp.accelerations;
    node["effort"] = trjp.effort;
    node["positions"] = trjp.positions;
    node["time_from_start"] = trjp.time_from_start;
    node["velocities"] = trjp.velocities;

    return node;
  }

  static bool decode(const Node& node, trajectory_msgs::JointTrajectoryPoint& trjp)
  {
    trjp.accelerations = node["accelerations"].as<std::vector<double>>();
    trjp.effort = node["effort"].as<std::vector<double>>();
    trjp.positions = node["positions"].as<std::vector<double>>();
    trjp.time_from_start = node["time_from_start"].as<ros::Duration>();
    trjp.velocities = node["velocities"].as<std::vector<double>>();
    return true;
  }
};

template <>
struct convert<trajectory_msgs::JointTrajectory>
{
  static Node encode(const trajectory_msgs::JointTrajectory& traj)
  {
    Node node;
    node["header"] = traj.header;
    node["joint_names"] = traj.joint_names;
    node["points"] = traj.points;
    return node;
  }

  static bool decode(const Node& node, trajectory_msgs::JointTrajectory& traj)
  {
    // if(!node.IsSequence() || node.size() != 3) {
    //   return false;
    // }

    traj.header = node["header"].as<std_msgs::Header>();
    traj.joint_names = node["joint_names"].as<std::vector<std::string>>();
    traj.points = node["points"].as<std::vector<trajectory_msgs::JointTrajectoryPoint>>();

    return true;
  }
};

}  // namespace YAML

#endif