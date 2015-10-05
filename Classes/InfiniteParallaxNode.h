//
//  InfiniteParallaxNode.h
//  paralaxDemo
//
//  Created by NguyenHuy on 8/21/15.
//
//

#ifndef __paralaxDemo__InfiniteParallaxNode__
#define __paralaxDemo__InfiniteParallaxNode__

#include <stdio.h>
USING_NS_CC;
class PointObject : public Ref
{
public:
    inline void setRation(Point ratio) {_ratio = ratio;}
    inline void setOffset(Point offset) {_offset = offset;}
    inline void setChild(Node *var) {_child = var;}
    inline Point getOffset() const {return _offset;}
    inline Node* getChild() const {return _child;}
private:
    Point _ratio;
    Point _offset;
    Node* _child;
};

class InfiniteParallaxNode : public ParallaxNode
{
public:
    static InfiniteParallaxNode* create();
    void updatePosition();
};
#endif /* defined(__paralaxDemo__InfiniteParallaxNode__) */
