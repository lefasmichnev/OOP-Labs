#include <iostream>
#include <vector>
  
using namespace std;

class Music
{
  public:
    void info() { 
      cout << "Music" << endl; 
    }
};
  
class Architecture
{
  public:
    void info() { 
      cout << "Architecture" << endl; 
    }
};
  
class Paintings
{
  public:        
    void info() { 
      cout << "Paintings" << endl; 
    }
};
  
class Drawings
{
  public:    
    void info() { 
      cout << "Drawings" << endl; 
    }
};
  
class Sculpture
{
  public:    
    void info() { 
      cout << "Sculpture" << endl; 
    }
};
  
  

class Stuff 
{
  public:
    vector<Music> vi; 
    vector<Architecture>    va; 
    vector<Paintings>  vh;     
    vector<Drawings>  vc;     
    vector<Sculpture>  ve; 
    void info() {   
      int i;
      for(i=0; i<vi.size(); ++i)  vi[i].info();
      for(i=0; i<va.size(); ++i)  va[i].info();
      for(i=0; i<vh.size(); ++i)  vh[i].info();
      for(i=0; i<vc.size(); ++i)  vc[i].info();
      for(i=0; i<ve.size(); ++i)  ve[i].info();
    }
};
  
  

 
class StuffBuilder
{
  protected: 
    Stuff* p;
  public:    
    StuffBuilder(): p(0) {}
    virtual ~StuffBuilder() {}
    virtual void createStuff() {}
    virtual void buildMusic() {}
    virtual void buildArchitecture() {}
    virtual void buildPaintings() {}
    virtual void buildDrawings() {}
    virtual void buildSculpture() {}    
    virtual Stuff* getStuff() { return p; }    
};
  
  

class GeneralArtBuilder: public StuffBuilder
{    
  public:    
    void createStuff() { p = new Stuff; }
    void buildMusic() { p->vi.push_back( Music()); }
    void buildArchitecture() { p->va.push_back( Architecture()); }
    void buildPaintings() { p->vh.push_back( Paintings()); }    
    void buildDrawings() { p->vc.push_back( Drawings()); }
};
  
  

class ModernArtBuilder: public StuffBuilder
{    
  public:    
    void createStuff() { p = new Stuff; }
    void buildMusic() { p->vi.push_back( Music()); }
    void buildArchitecture() { p->va.push_back( Architecture()); }
    void buildPaintings() { p->vh.push_back( Paintings()); }
    void buildSculpture() { p->ve.push_back( Sculpture()); }    
};
  
  

class Director
{    
  public:    
    Stuff* createStuff( StuffBuilder & builder ) 
    { 
        builder.createStuff();
        builder.buildMusic();
        builder.buildArchitecture();
        builder.buildPaintings();
        builder.buildDrawings();
        builder.buildSculpture();
        return( builder.getStuff());
    }
};
  
  
int main()
{   
    Director dir;
    GeneralArtBuilder ga_builder;
    ModernArtBuilder ma_builder;
     
    Stuff * ga = dir.createStuff( ga_builder);
    Stuff * ma = dir.createStuff( ma_builder);
    cout << "General art: " << endl;
    ga->info();
    cout << "\nModern art: " << endl;
    ma->info();
    
  
    return 0;
}