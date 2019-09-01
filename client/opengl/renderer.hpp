#ifndef OPENGL_RENDERER_HPP
#define OPENGL_RENDERER_HPP

#include <glm/glm.hpp>

class Program;
class OpenGLVertexArray;
class OpenGLTexture2D;

class OpenGLRenderer {
   public:
    OpenGLRenderer();

    ~OpenGLRenderer();

    static void clear();

    static void clear_colour(const glm::vec3& rgb);

    static void clear_colour(const glm::vec4& rgba);

    static void draw(const Program& program, const OpenGLVertexArray& va);

    static void draw(const Program& program,
                     const OpenGLTexture2D& texture,
                     const OpenGLVertexArray& va);

   private:
};

#endif
