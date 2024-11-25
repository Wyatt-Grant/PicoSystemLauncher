#include "picosystem.hpp"

#include <cmath>
#include <utility>
#include <vector>

using namespace picosystem;

/**
 * gets spiral co-ords for position of orbs
 * 
 * @return pair.
 */
std::pair<double, double> spiral(double distance) {
    // Constants to control the spiral shape
    double a = 5.0;    // Starting radius
    double b = 1.35;   // Controls how tight the spiral is
    
    // Adjust theta to better control the spacing
    double theta = sqrt(distance);  // Adjusting the relationship between distance and theta

    // Spiral equation: r = a + b * θ
    double r = a + b * theta;

    // Convert polar to Cartesian coordinates
    double x = r * fcos(theta);
    double y = r * fsin(theta);

    return std::make_pair(x, y);
}

/**
 * return the distance if the (x, y) point is on the spiral
 * 
 * @return double.
 */
double isPointOnSpiral(int x, int y, double startDistance, double endDistance, double threshold = 1.0) {
    double stepSize = 2.0;  // Small step size to walk along the spiral

    for (double d = startDistance; d <= endDistance; d += stepSize) {
        // Get the spiral coordinates for the current distance
        std::pair<double, double> spiralCoords = spiral(d);

        // Calculate the Euclidean distance between the point and the spiral coords
        double distToPoint = sqrt(pow(x - spiralCoords.first, 2) + pow(y - spiralCoords.second, 2));

        // If the distance to the point is within the threshold, return the spiral distance
        if (distToPoint <= threshold) {
            return d;  // Return the current distance on the spiral
        }
    }

    // If no point on the spiral is close enough to (x, y), return -1 (meaning not found)
    return -1.0;
}

/**
 * @brief 
 * 
 * @return int.
 */
int removeDuplicates(std::vector<int>& vec) {
    if (vec.size() < 3) return 0; // If the vector has fewer than 3 elements, no need to process

    int removedCount = 0; // Counter for the number of removed elements

    // Iterate through the vector and look for 3 or more consecutive duplicates
    for (size_t i = 0; i < vec.size() - 2; ) {
        // Check if we have 3 consecutive identical values
        if (vec[i] == vec[i + 1] && vec[i] == vec[i + 2] && vec[i] != -1) {
            // Find the range of consecutive duplicates
            size_t j = i + 3;
            while (j < vec.size() && vec[j] == vec[i]) {
                ++j;
            }
            // Calculate how many elements to remove
            removedCount += j - i;

            // Erase the consecutive duplicates from the vector
            // vec.erase(vec.begin() + i, vec.begin() + j);
            for (int32_t r = i; r < i + removedCount; r++) {
                vec[r] = -1;
            }
            
        } else {
            // Move to the next element if no 3 consecutive duplicates found
            ++i;
        }
    }

    return removedCount; // Return the number of removed elements
}

/**
 * set ball color by int
 * 
 * @return void.
 */
void setColorByInt(int32_t index) {
    switch (index) {
        case 0:
            pen(0, 0, 15);
            break;
        case 1:
            pen(0, 15, 0);
            break;
        case 2:
            pen(15, 0, 0);
            break;
        case 3:
            pen(12, 12, 12);
            break;
        case 4:
            pen(15, 0, 15);
            break;
        case 5:
            pen(15, 15, 0);
            break;
        default:
            pen(15, 15, 15);
            break;
    }
}