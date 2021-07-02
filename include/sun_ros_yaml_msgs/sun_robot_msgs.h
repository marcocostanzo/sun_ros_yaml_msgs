#ifndef SUN_ROS_YAML_MSGS_SUN_ROBOT_MSGS_H
#define SUN_ROS_YAML_MSGS_SUN_ROBOT_MSGS_H

#include "yaml-cpp/yaml.h"
#include "sun_ros_yaml_msgs/std_msgs.h"
#include "sun_ros_yaml_msgs/geometry_msgs.h"
#include "sun_robot_msgs/CartesianTrajectory.h"

namespace YAML
{

template <>
struct convert<sun_robot_msgs::CartesianTrajectoryPoint>
{
  static Node encode(const sun_robot_msgs::CartesianTrajectoryPoint& trajp)
  {
    Node node;

    node["pose"] = trajp.pose;
    node["velocity"] = trajp.velocity;
    node["acceleration"] = trajp.acceleration;
    node["time_from_start"] = trajp.time_from_start;

    return node;
  }

  static bool decode(const Node& node, sun_robot_msgs::CartesianTrajectoryPoint& trajp)
  {
    trajp.pose = node["pose"].as<geometry_msgs::Pose>();
    trajp.velocity = node["velocity"].as<geometry_msgs::Twist>();
    trajp.acceleration = node["acceleration"].as<geometry_msgs::Twist>();
    trajp.time_from_start = node["time_from_start"].as<ros::Duration>();

    return true;
  }
};

template <>
struct convert<sun_robot_msgs::CartesianTrajectory>
{
  static Node encode(const sun_robot_msgs::CartesianTrajectory& traj)
  {
    Node node;

    node["header"] = traj.header;
    node["points"] = traj.points;

    return node;
  }

  static bool decode(const Node& node, sun_robot_msgs::CartesianTrajectory& traj)
  {
    traj.header = node["header"].as<std_msgs::Header>();
    traj.points = node["points"].as<std::vector<sun_robot_msgs::CartesianTrajectoryPoint>>();
    return true;
  }
};

}  // namespace YAML

#endif