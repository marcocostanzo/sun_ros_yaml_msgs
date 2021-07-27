#ifndef SUN_ROS_YAML_MSGS_YAML_IO_H
#define SUN_ROS_YAML_MSGS_YAML_IO_H

#include "yaml-cpp/yaml.h"
#include <fstream>

namespace YAML {

template <typename T>
void saveOnFile(const std::string &file, T resource,
                const std::string &root_yaml_node = "") {
  YAML::Node out_yaml;
  if (root_yaml_node == "" || root_yaml_node.empty()) {
    out_yaml = resource;
  } else {
    out_yaml[root_yaml_node] = resource;
  }

  YAML::Emitter yaml_emitter;
  yaml_emitter << out_yaml;
  std::ofstream outfile(file);
  outfile << yaml_emitter.c_str();
  outfile.close();
}

template <typename T>
T loadFromFile(const std::string &file,
               const std::string &root_yaml_node = "") {
  try {
    YAML::Node db_yaml = YAML::LoadFile(file);
    if (root_yaml_node == "" || root_yaml_node.empty()) {
      return db_yaml.as<T>();
    } else {
      return db_yaml[root_yaml_node].as<T>();
    }
  } catch (const YAML::Exception &e) { 
      std::cerr << "YAML::loadFromFile error [" + file + "](/" + root_yaml_node + ")\n";
      throw;
  }
}

} // namespace YAML

#endif