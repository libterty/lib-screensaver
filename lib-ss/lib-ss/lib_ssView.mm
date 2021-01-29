//
//  lib_ssView.m
//  lib-ss
//
//  Created by 李韻晟 on 2021/1/29.
//

#import "lib_ssView.h"
#import "CoreGraphics/CoreGraphics.h"
#import "Quartz/Quartz.h"
#import "simulator/simulator.hpp"

@implementation lib_ssView {
    cjh::Graph graph;
    cjh::Simulator sim;
}

- (instancetype)initWithFrame:(NSRect)frame isPreview:(BOOL)isPreview
{
    self = [super initWithFrame:frame isPreview:isPreview];
    if (self) {
        [self setAnimationTimeInterval:1/30.0];
        // set the simulation transit
        sim.setTime(0.0);
        sim.setTimeStep(1 / 30.0);
        sim.setCenter(frame.size.width * 0.5, frame.size.height * 0.5);

        // generate random grpah
        cjh::createRandomCompleteGraph(frame.size.width, frame.size.height, 15, 60, graph);
    }
    return self;
}

- (void)startAnimation
{
    [super startAnimation];
}

- (void)stopAnimation
{
    [super stopAnimation];
}

- (void)drawRect:(NSRect)rect
{
    [super drawRect:rect];
}

- (void) drawGraph:(CGContextRef) ctx {
  auto& vertices = self -> graph.getVertices();
  CGContextSetRGBFillColor(ctx, 0, 0, 0, 1);
  CGContextSetRGBStrokeColor(ctx, 0, 0, 0, 1);
  CGContextSetLineWidth(ctx, 1.0);

  for(size_t i = 0; i < vertices.size(); ++i) {
    CGContextBeginPath(ctx);
    auto& v = vertices[i];
    CGContextAddArc(ctx, v[0], v[1], 10, 0, 2 * M_PI, 1);
    CGContextFillPath(ctx);
    CGContextClosePath(ctx);
  }

  for(size_t i = 0; i < vertices.size(); ++i) {
    uint32_t from_vertex = static_cast<uint32_t>(i);
    auto iter = self -> graph.getConnectivityStartIterator(from_vertex);
    auto end = self -> graph.getConnectivityEndIterator(from_vertex);
    for(; iter != end; ++iter) {
      uint32_t to_vertex = *iter;

      auto& v1 = vertices[from_vertex];
      auto& v2 = vertices[to_vertex];

      CGContextBeginPath(ctx);
      CGContextMoveToPoint(ctx, v1[0], v1[1]);
      CGContextAddLineToPoint(ctx, v2[0], v2[1]);
      CGContextStrokePath(ctx);
      CGContextClosePath(ctx);
    }
  }
}

- (void) drawScene {
    CGContextRef ctx = (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
    
    CGContextSetRGBFillColor(ctx, 1, 1, 1, 1);
    CGContextFillRect(ctx, self.frame);
    
    [self drawGraph:ctx];
    
    sim.updateGraphDynamics(self -> graph);
}

- (void)animateOneFrame
{
    return;
}

- (BOOL)hasConfigureSheet
{
    return NO;
}

- (NSWindow*)configureSheet
{
    return nil;
}

@end
