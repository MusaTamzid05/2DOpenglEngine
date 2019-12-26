#include "util.h"
#include <iostream>

namespace Util {
    void print_mat4(const glm::mat4& mat) {

        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
        for(unsigned int row = 0 ; row < 4 ; row++) {
            for(unsigned int col = 0 ; col < 4 ; col++) 
                std::cout << mat[row][col]  << " ";
            std::cout << "\n";
        }
        std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";

    }
};
