#include <raylib.h>
#include <vector>
class Entity{
  private:
    static std::vector<Texture2D> texturePool;
    Texture2D currentTexture;
    Rectangle rec;

  public:
    Entity (std::vector<const char * >& TexturePath);
    void update();
    void animate();
};
