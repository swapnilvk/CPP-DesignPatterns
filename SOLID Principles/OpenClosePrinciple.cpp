#include<iostream>
#include<vector>
#include<string>

enum class Color {Red, Green, Blue};
enum class Size {Lage, Small, Medium};

struct Product
{
    std::string name;
    Color color;
    Size size;
};

class ProductFinder
{
   public:
    typedef std::vector<Product*> Items;

    Items by_color(Items items, Color color) //Filter by color
    {
        Items result;
        for(auto iter: items)
        {
            if(iter->color == color)
            result.push_back(iter);
        }
        return result;
    }

    Items by_size(Items items, Size size) //Filter by size
    {
        Items result;
        for(auto iter: items)
        {
            if(iter->size == size)
            result.push_back(iter);
        }
        return result;
    }

       Items by_size_and_color(Items items, Size size, Color color) //Filter by size and color
    {
        Items result;
        for(auto iter: items)
        {
            if(iter->size == size && iter->color == color)
            result.push_back(iter);
        }
        return result;
    }

};

template <typename T> class ISpecification
{
    public:
    virtual bool is_satisfied(T *item) = 0;
};

template <typename T> class IFilter
{
    virtual std:: vector<T*> filter(std::vector<T*>, ISpecification<T> &spec) = 0;
};

class ColorSpecification: public ISpecification<Product>
{
    public:
    Color color;
    //to avoid implicit conversion of color this may lead to unexpected results. 
    //We can make the constructor explicit with the help of explicit keyword
    explicit ColorSpecification (const Color color)
    :color{color}
    {

    }
    bool is_satisfied(Product *item) override
    {   
        return item->color == color;
    }

};

class BetterFilter : public IFilter<Product>
{   
    typedef std::vector<Product*> Items;
    public:
    std:: vector<Product*> filter(std::vector<Product*> items, ISpecification<Product> &spec)
    {
        Items results;
        for(auto p: items)
        {
            if(spec.is_satisfied(p))
            {
                results.push_back(p);
            }
        }
        return results;
    }
};

int main()
{
    Product apple{"Apple",Color::Green, Size::Small };
    Product tree{"Tree",Color::Green, Size::Medium };
    Product house{"House",Color::Blue, Size::Lage };

    std::vector<Product*> all{&tree, &apple, &house};
    BetterFilter bf;
    ColorSpecification green(Color::Green);

    auto green_things = bf.filter(all, green);
    for (auto iter : green_things)
        std::cout<<iter->name<<" is green"<<std::endl;

    getchar();
    return 0;
}
