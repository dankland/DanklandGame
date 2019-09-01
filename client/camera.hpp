#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
   public:
    Camera() : pos_{0.0, 0.0}, near_{0.0}, far_{1.0} {
    }

    void set_position(const glm::vec2& pos) {
        pos_ = pos;
    }

    [[nodiscard]] glm::mat4 matrix() const noexcept {
        const glm::mat4 projection =
            glm::ortho(pos_.x - 1.0f, pos_.x + 1.0f, pos_.y - 1.0f, pos_.y + 1.0f, near_, far_);
        const glm::mat4 view = glm::mat4(1.0f);
        return projection * view;
    }

   private:
    glm::vec2 pos_;
    float near_;
    float far_;
};

#endif
