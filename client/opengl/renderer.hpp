#ifndef OPENGL_RENDERER_HPP
#define OPENGL_RENDERER_HPP

#include <glm/glm.hpp>
#include "program.hpp"
#include "vertex_array.hpp"

class OpenGLVertexArray;
class OpenGLTexture2D;
class Camera;

struct Rect {
    Rect(const float x, const float y, const float w, const float h) : x_{x}, y_{y}, w_{w}, h_{h} {
    }

    float x_;
    float y_;
    float w_;
    float h_;
};

class OpenGLRenderer {
   public:
    OpenGLRenderer();

    ~OpenGLRenderer();

    static void clear();

    static void clear_colour(const glm::vec3& rgb);

    static void clear_colour(const glm::vec4& rgba);

    void draw_rect(const Camera& camera, const Rect& rect, const glm::vec3& rgb);

   private:
    Program colour_program_;
    OpenGLVertexArray colour_va_;
};

#endif
