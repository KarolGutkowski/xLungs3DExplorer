//
// Created by nope1 on 12/26/2023.
//
#include "glad/glad.h"

void setGlOptions()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
