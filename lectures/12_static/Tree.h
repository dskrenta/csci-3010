#ifndef _TREE_H_
#define _TREE_H_

class Tree {
    public:
        Tree() { number_instances_++; }

        virtual void Seed() { number_seeds_ += 1; };

        int get_number_seeds() { return number_seeds_; }

        static int number_instances_;

    private:
      static int number_seeds_;
};

class Sub : public Tree {
  public:
     void Seed() {
       Tree::Seed();
       Tree::Seed();
     }
};

#endif // _TREE_H_
