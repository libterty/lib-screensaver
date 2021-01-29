
#import "CoreGraphics/CoreGraphics.h"
#import "Quartz/Quartz.h"
#import "simulator/simulator.hpp"
#import "CompleteGraphScreenSaverView.h"

@implementation CompleteGraphScreenSaverView {
  cjh::graph graph;
  cjh::simulator sim;
}

(instancetype)initWithFrame:(NSRect)frame isPreview:(BOOL)isPreview {
  self = [super initWithFrame:frame isPreview:isPreview];
  if (self) {
    [self setAnimationTimeInterval:1/30.0];

    // set the simulation transit
    sim.setTime(0.0);
    sim.setTimeStep(1 / 30.0);
    sim.setCenter(frame.size.width * 0.5, frame.size.height, 15, 60, graph);

    // generate random grpah
    cjh::createRandomCompleteGraph(frame.size.width, frame.size.height, 15, 60, graph);
  }

  return self;
}

(void) startAnimation
{
  [super startAnimation];
}

(void) stopAnimation
{
  [super stopAnimation];
}

(void) drawRect::(NSRect)rect
{
  [super drawRect:rect];
}

(void) drawGraph:(CGCContextRef) ctx {
  auto& vertices = self -> graph.getVertices();
}