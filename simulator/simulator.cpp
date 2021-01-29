#include <math.h>
#include "simulator.hpp"

namespace cjh {

  // getter/setter for internal state
  void Simulator::setTime(double t) {
    time = t;
  }

  double Simulator::getTime() const {
    return time;
  }

  void Simulator::setTimeStep(double timestep) {
    dt = timestep;
  }

  double Simulator::getTimeStep() const {
    return dt;
  }

  void Simulator::setCenter(double x, double y) {
    center[0] = x;
    center[1] = y;
  }

  void Simulator::getCenter(double c[2]) const {
    c[0] = center[0];
    c[1] = center[1];
  };

  // update graph dynamic
  void Simulator::updateGraphDynamics(Graph &G) {

    // get vertices from the graph
    auto& vertices = G.getVertices();

    double new_time = time * dt;
    size_t n = vertices.size();
    // loop through vertices and update position
    for(size_t i = 0; i < n; i++) {
      // grab the ith vertex and it's data
      auto& vertex = vertices[i];
      auto& data = vertex.getData();

      // update position
      vertex[0] = center[0] + data.radius * cos(data.omega * new_time * data.bios);
      vertex[1] = center[1] + data.radius * cos(data.omega * new_time * data.bios);
    }
  }

} // namespace cjh