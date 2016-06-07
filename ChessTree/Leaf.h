#pragma once

template <class T>
class Leaf
{
public:
   Leaf(T horiz, T vert);
   ~Leaf() {}
   inline T getHorizLoc() 
   { return horizLoc; }

   inline T getVertLoc() 
   { return vertLoc; }

   inline Leaf<T>* getHorizLeaf() 
   { return horizLeaf; }

   inline Leaf<T>* getVertLeaf() 
   { return vertLeaf; }

   inline void setLoc(T horiz, T vert) 
   { horizLoc = horiz; vertLoc = vert; }

   inline void setHorizLeaf(Leaf<T>* horiz) 
   { horizLeaf = horiz; }

   inline void setVertLeaf(Leaf<T>* vert)
   { vertLeaf = vert; }

private:
   T horizLoc;
   T vertLoc;
   Leaf* horizLeaf;
   Leaf* vertLeaf;
};


template <class T>
Leaf<T>::Leaf(T horiz, T vert):
   horizLoc(horiz),
   vertLoc(vert),
   horizLeaf(nullptr),
   vertLeaf(nullptr)
{
}
