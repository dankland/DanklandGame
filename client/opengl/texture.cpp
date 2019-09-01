#define STB_IMAGE_IMPLEMENTATION
#include "texture.hpp"
#include "stb/stb_image.h"

OpenGLTexture2D::OpenGLTexture2D(const std::string& path) {
    stbi_set_flip_vertically_on_load(1);
    stbi_uc* data = stbi_load(path.c_str(), &width_, &height_, &channels_, 4);

    glCreateTextures(GL_TEXTURE_2D, 1, &id_);
    glTextureStorage2D(id_, 1, GL_RGBA8, width_, height_);

    glTextureParameteri(id_, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameteri(id_, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTextureSubImage2D(id_, 0, 0, 0, width_, height_, GL_RGBA, GL_UNSIGNED_BYTE, data);

    stbi_image_free(data);
}

OpenGLTexture2D::~OpenGLTexture2D() {
    glDeleteTextures(1, &id_);
}

[[nodiscard]] int OpenGLTexture2D::get_width() const noexcept {
    return width_;
}

[[nodiscard]] int OpenGLTexture2D::get_height() const noexcept {
    return height_;
}

void OpenGLTexture2D::bind() const noexcept {
    glBindTexture(GL_TEXTURE_2D, id_);
}
