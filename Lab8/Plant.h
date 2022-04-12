#pragma once 

class Plant{
    protected:
        int rapeningTime;
        Plant(int i) : rapeningTime(i){};
    public:
        int getRapeningTime() { return this->rapeningTime;}
        virtual bool isVegetable() {return false;}
};

class Vegetable : public Plant{
    public:
        bool isVegetable(){return true;};
    protected:
        Vegetable(int i) : Plant(i){}
};

class Flower : public Plant{
    protected:
        Flower(int i) : Plant(i){}
};

class Potatoe : public Vegetable{
    public:
        static Potatoe* instance();
    private:
        Potatoe() : Vegetable(5){};
        static Potatoe *m_instance;
};

class Pea : public Vegetable{
    public:
        static Pea* instance();
    private:
        Pea() : Vegetable(3){};
        static Pea *m_instance;
};

class Onion : public Vegetable
{
    public:
        static Onion* instance();
    private:
        Onion() : Vegetable(4) {}
        static Onion* m_instance;
};

class Rose : public Flower
{
    public:
        static Rose* instance();
    private:
        Rose() : Flower(8) {}
        static Rose* m_instance;
};

class Carnation : public Flower
{
    public:
        static Carnation* instance();
    private:
        Carnation() : Flower(10) {}
        static Carnation* m_instance;
};

class Tulip : public Flower
{
    public:
        static Tulip* instance();
    private:
        Tulip() : Flower(7) {}
        static Tulip* m_instance;
};