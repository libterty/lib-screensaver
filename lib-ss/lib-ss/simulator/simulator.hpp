#ifndef simulator_hpp
#define simulator_hpp

#include <iostream>
#include "../graph/graph.hpp"

using namespace std;

namespace cjh {
  
  class Simulator {
  public:
    Simulator() = default;
    ~Simulator() = default;

    // getter/setter for internal state
    void setTime(double t);
    double getTime() const;

    void setTimeStep(double timestep);
    double getTimeStep() const;

    void setCenter(double x, double y);
    void getCenter(double c[2]) const;

    // update graph dynamic
    void updateGraphDynamics(Graph& G);

  private:
    /* data */
    double time, dt;
    double center[2];
  };
  
} // namespace cjh

#endif /* simulator_hpp */
