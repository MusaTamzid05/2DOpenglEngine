#include "light_property.h"


namespace Shape {

    std::ostream& operator<<(std::ostream& out , const LightProperty& light_property) {

        out << "Light Property:\n";
        out << "Pos : " << light_property.position.x << " , " <<  light_property.position.y << " , " << light_property.position.z << "\n";

        out << "Ambient : " << light_property.ambient.x << " , " <<  light_property.ambient.y << " , " << light_property.ambient.z << "\n";

        out << "Diffuse : " << light_property.diffuse.x << " , " <<  light_property.diffuse.y << " , " << light_property.diffuse.z << "\n";

        out << "Specular: " << light_property.specular.x << " , " <<  light_property.specular.y << " , " << light_property.specular.z;

    }
};
