#include "shape.h"

Axes::Axes(std::vector<Vertex>& vertices) {
    Vertex vert1;
    Vertex vert2;
    Vertex vert3;
    Vertex vert4;
    Vertex vert5;
    Vertex vert6;

    vert1.position = glm::vec3();    vert1.normal = glm::vec3();    vert1.texCoord = glm::vec2();
    vert2.position = glm::vec3();    vert2.normal = glm::vec3();    vert2.texCoord = glm::vec2();
    vert3.position = glm::vec3();    vert3.normal = glm::vec3();    vert3.texCoord = glm::vec2();
    vert4.position = glm::vec3();    vert4.normal = glm::vec3();    vert4.texCoord = glm::vec2();
    vert5.position = glm::vec3();    vert5.normal = glm::vec3();    vert5.texCoord = glm::vec2();
    vert6.position = glm::vec3();    vert6.normal = glm::vec3();    vert6.texCoord = glm::vec2();

    vertices.push_back(vert1);
    vertices.push_back(vert2);
    vertices.push_back(vert3);
    vertices.push_back(vert4);
    vertices.push_back(vert5);
    vertices.push_back(vert6);
}

Graph::Graph(std::vector<Vertex>& vertices) {

}

Plane::Plane(std::vector<Vertex>& vertices) {
    Vertex vert1;
    Vertex vert2;
    Vertex vert3;
    Vertex vert4;
    Vertex vert5;
    Vertex vert6;

    vert1.position = glm::vec3();    vert1.normal = glm::vec3();    vert1.texCoord = glm::vec2();
    vert2.position = glm::vec3();    vert2.normal = glm::vec3();    vert2.texCoord = glm::vec2();
    vert3.position = glm::vec3();    vert3.normal = glm::vec3();    vert3.texCoord = glm::vec2();
    vert4.position = glm::vec3();    vert4.normal = glm::vec3();    vert4.texCoord = glm::vec2();
    vert5.position = glm::vec3();    vert5.normal = glm::vec3();    vert5.texCoord = glm::vec2();
    vert6.position = glm::vec3();    vert6.normal = glm::vec3();    vert6.texCoord = glm::vec2();

    vertices.push_back(vert1);
    vertices.push_back(vert2);
    vertices.push_back(vert3);
    vertices.push_back(vert4);
    vertices.push_back(vert5);
    vertices.push_back(vert6);
}

Tetrahedon::Tetrahedon(std::vector<Vertex>& vertices) {
    Vertex vert1;
    Vertex vert2;
    Vertex vert3;
    Vertex vert4;
    Vertex vert5;
    Vertex vert6;

    Vertex vert7;
    Vertex vert8;
    Vertex vert9;

    Vertex vert10;
    Vertex vert11;
    Vertex vert12;

    Vertex vert13;
    Vertex vert14;
    Vertex vert15;
    
    Vertex vert16;
    Vertex vert17;
    Vertex vert18;

     vert1.position = glm::vec3();     vert1.normal = glm::vec3();     vert1.texCoord = glm::vec2();
     vert2.position = glm::vec3();     vert2.normal = glm::vec3();     vert2.texCoord = glm::vec2();
     vert3.position = glm::vec3();     vert3.normal = glm::vec3();     vert3.texCoord = glm::vec2();
     vert4.position = glm::vec3();     vert4.normal = glm::vec3();     vert4.texCoord = glm::vec2();
     vert5.position = glm::vec3();     vert5.normal = glm::vec3();     vert5.texCoord = glm::vec2();
     vert6.position = glm::vec3();     vert6.normal = glm::vec3();     vert6.texCoord = glm::vec2();
                                                                     
     vert7.position = glm::vec3();     vert7.normal = glm::vec3();     vert7.texCoord = glm::vec2();
     vert8.position = glm::vec3();     vert8.normal = glm::vec3();     vert8.texCoord = glm::vec2();
     vert9.position = glm::vec3();     vert9.normal = glm::vec3();     vert9.texCoord = glm::vec2();
                                                                     
    vert10.position = glm::vec3();    vert10.normal = glm::vec3();    vert10.texCoord = glm::vec2();
    vert11.position = glm::vec3();    vert11.normal = glm::vec3();    vert11.texCoord = glm::vec2();
    vert12.position = glm::vec3();    vert12.normal = glm::vec3();    vert12.texCoord = glm::vec2();
                                                                     
    vert13.position = glm::vec3();    vert13.normal = glm::vec3();    vert13.texCoord = glm::vec2();
    vert14.position = glm::vec3();    vert14.normal = glm::vec3();    vert14.texCoord = glm::vec2();
    vert15.position = glm::vec3();    vert15.normal = glm::vec3();    vert15.texCoord = glm::vec2();
    vert16.position = glm::vec3();    vert16.normal = glm::vec3();    vert16.texCoord = glm::vec2();
    vert17.position = glm::vec3();    vert17.normal = glm::vec3();    vert17.texCoord = glm::vec2();
    vert18.position = glm::vec3();    vert18.normal = glm::vec3();    vert18.texCoord = glm::vec2();

    vertices.push_back(vert1);        
    vertices.push_back(vert2);        
    vertices.push_back(vert3);        
    vertices.push_back(vert4);        
    vertices.push_back(vert5);        
    vertices.push_back(vert6);        
    vertices.push_back(vert7);
    vertices.push_back(vert8);            
    vertices.push_back(vert9);        
    vertices.push_back(vert10);       
    vertices.push_back(vert11);       
    vertices.push_back(vert12);       
    vertices.push_back(vert13);       
    vertices.push_back(vert14);
    vertices.push_back(vert15);           
    vertices.push_back(vert16);       
    vertices.push_back(vert17);       
    vertices.push_back(vert18);       
}                                         

Cube::Cube(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices) {
    Vertex vert1;
    Vertex vert2;
    Vertex vert3;
    Vertex vert4;
    Vertex vert5;
    Vertex vert6;

    Vertex vert7;
    Vertex vert8;
    Vertex vert9;
    Vertex vert10;
    Vertex vert11;
    Vertex vert12;

    Vertex vert13;
    Vertex vert14;
    Vertex vert15;
    Vertex vert16;
    Vertex vert17;
    Vertex vert18;

    Vertex vert19;
    Vertex vert20;
    Vertex vert21;
    Vertex vert22;
    Vertex vert23;
    Vertex vert24;

    Vertex vert25;
    Vertex vert26;
    Vertex vert27;
    Vertex vert28;
    Vertex vert29;
    Vertex vert30;

    Vertex vert31;
    Vertex vert32;
    Vertex vert33;
    Vertex vert34;
    Vertex vert35;
    Vertex vert36;

     vert1.position = glm::vec3(-0.5f, -0.5f, -0.5f);     vert1.normal = glm::vec3(0.0f, 1.0f, 0.0f);     vert1.texCoord = glm::vec2(0.0f, 0.0f);
     vert2.position = glm::vec3( 0.5f, -0.5f, -0.5f);     vert2.normal = glm::vec3(0.0f, 1.0f, 0.0f);     vert2.texCoord = glm::vec2(1.0f, 0.0f);
     vert3.position = glm::vec3( 0.5f,  0.5f, -0.5f);     vert3.normal = glm::vec3(0.0f, 1.0f, 0.0f);     vert3.texCoord = glm::vec2(1.0f, 1.0f);
     vert4.position = glm::vec3( 0.5f,  0.5f, -0.5f);     vert4.normal = glm::vec3(0.0f, 1.0f, 0.0f);     vert4.texCoord = glm::vec2(1.0f, 1.0f);
     vert5.position = glm::vec3(-0.5f,  0.5f, -0.5f);     vert5.normal = glm::vec3(0.0f, 1.0f, 0.0f);     vert5.texCoord = glm::vec2(0.0f, 1.0f);
     vert6.position = glm::vec3(-0.5f, -0.5f, -0.5f);     vert6.normal = glm::vec3(0.0f, 1.0f, 0.0f);     vert6.texCoord = glm::vec2(0.0f, 0.0f);
                                                                                                        
     vert7.position = glm::vec3(-0.5f, -0.5f,  0.5f);     vert7.normal = glm::vec3(0.0f, 1.0f, 0.0f);     vert7.texCoord = glm::vec2(0.0f, 0.0f);
     vert8.position = glm::vec3( 0.5f, -0.5f,  0.5f);     vert8.normal = glm::vec3(0.0f, 1.0f, 0.0f);     vert8.texCoord = glm::vec2(1.0f, 0.0f);
     vert9.position = glm::vec3( 0.5f,  0.5f,  0.5f);     vert9.normal = glm::vec3(0.0f, 1.0f, 0.0f);     vert9.texCoord = glm::vec2(1.0f, 1.0f);
    vert10.position = glm::vec3( 0.5f,  0.5f,  0.5f);    vert10.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert10.texCoord = glm::vec2(1.0f, 1.0f);
    vert11.position = glm::vec3(-0.5f,  0.5f,  0.5f);    vert11.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert11.texCoord = glm::vec2(0.0f, 1.0f);
    vert12.position = glm::vec3(-0.5f, -0.5f,  0.5f);    vert12.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert12.texCoord = glm::vec2(0.0f, 0.0f);
                                                                                                        
    vert13.position = glm::vec3(-0.5f,  0.5f,  0.5f);    vert13.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert13.texCoord = glm::vec2(1.0f, 0.0f);
    vert14.position = glm::vec3(-0.5f,  0.5f, -0.5f);    vert14.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert14.texCoord = glm::vec2(1.0f, 1.0f);
    vert15.position = glm::vec3(-0.5f, -0.5f, -0.5f);    vert15.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert15.texCoord = glm::vec2(0.0f, 1.0f);
    vert16.position = glm::vec3(-0.5f, -0.5f, -0.5f);    vert16.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert16.texCoord = glm::vec2(0.0f, 1.0f);
    vert17.position = glm::vec3(-0.5f, -0.5f,  0.5f);    vert17.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert17.texCoord = glm::vec2(0.0f, 0.0f);
    vert18.position = glm::vec3(-0.5f,  0.5f,  0.5f);    vert18.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert18.texCoord = glm::vec2(1.0f, 0.0f);
                                                                                                        
    vert19.position = glm::vec3( 0.5f,  0.5f,  0.5f);    vert19.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert19.texCoord = glm::vec2(1.0f, 0.0f);
    vert20.position = glm::vec3( 0.5f,  0.5f, -0.5f);    vert20.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert20.texCoord = glm::vec2(1.0f, 1.0f);
    vert21.position = glm::vec3( 0.5f, -0.5f, -0.5f);    vert21.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert21.texCoord = glm::vec2(0.0f, 1.0f);
    vert22.position = glm::vec3( 0.5f, -0.5f, -0.5f);    vert22.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert22.texCoord = glm::vec2(0.0f, 1.0f);
    vert23.position = glm::vec3( 0.5f, -0.5f,  0.5f);    vert23.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert23.texCoord = glm::vec2(0.0f, 0.0f);
    vert24.position = glm::vec3( 0.5f,  0.5f,  0.5f);    vert24.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert24.texCoord = glm::vec2(1.0f, 0.0f);
                                                                                                        
    vert25.position = glm::vec3(-0.5f, -0.5f, -0.5f);    vert25.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert25.texCoord = glm::vec2(0.0f, 1.0f);
    vert26.position = glm::vec3( 0.5f, -0.5f, -0.5f);    vert26.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert26.texCoord = glm::vec2(1.0f, 1.0f);
    vert27.position = glm::vec3( 0.5f, -0.5f,  0.5f);    vert27.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert27.texCoord = glm::vec2(1.0f, 0.0f);
    vert28.position = glm::vec3( 0.5f, -0.5f,  0.5f);    vert28.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert28.texCoord = glm::vec2(1.0f, 0.0f);
    vert29.position = glm::vec3(-0.5f, -0.5f,  0.5f);    vert29.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert29.texCoord = glm::vec2(0.0f, 0.0f);
    vert30.position = glm::vec3(-0.5f, -0.5f, -0.5f);    vert30.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert30.texCoord = glm::vec2(0.0f, 1.0f);
                                                                                                        
    vert31.position = glm::vec3(-0.5f,  0.5f, -0.5f);    vert31.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert31.texCoord = glm::vec2(0.0f, 1.0f);
    vert32.position = glm::vec3( 0.5f,  0.5f, -0.5f);    vert32.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert32.texCoord = glm::vec2(1.0f, 1.0f);
    vert33.position = glm::vec3( 0.5f,  0.5f,  0.5f);    vert33.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert33.texCoord = glm::vec2(1.0f, 0.0f);
    vert34.position = glm::vec3( 0.5f,  0.5f,  0.5f);    vert34.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert34.texCoord = glm::vec2(1.0f, 0.0f);
    vert35.position = glm::vec3(-0.5f,  0.5f,  0.5f);    vert35.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert35.texCoord = glm::vec2(0.0f, 0.0f);
    vert36.position = glm::vec3(-0.5f,  0.5f, -0.5f);    vert36.normal = glm::vec3(0.0f, 1.0f, 0.0f);    vert36.texCoord = glm::vec2(0.0f, 1.0f);

    vertices.push_back(vert1);
    vertices.push_back(vert2);
    vertices.push_back(vert3);
    vertices.push_back(vert4);
    vertices.push_back(vert5);
    vertices.push_back(vert6);
    vertices.push_back(vert7);
    vertices.push_back(vert8);
    vertices.push_back(vert9);
    vertices.push_back(vert10);
    vertices.push_back(vert11);
    vertices.push_back(vert12);
    vertices.push_back(vert13);
    vertices.push_back(vert14);
    vertices.push_back(vert15);
    vertices.push_back(vert16);
    vertices.push_back(vert17);
    vertices.push_back(vert18);
    vertices.push_back(vert19);
    vertices.push_back(vert20);
    vertices.push_back(vert21);
    vertices.push_back(vert22);
    vertices.push_back(vert23);
    vertices.push_back(vert24);
    vertices.push_back(vert25);
    vertices.push_back(vert26);
    vertices.push_back(vert27);
    vertices.push_back(vert28);
    vertices.push_back(vert29);
    vertices.push_back(vert30);
    vertices.push_back(vert31);
    vertices.push_back(vert32);
    vertices.push_back(vert33);
    vertices.push_back(vert34);
    vertices.push_back(vert35);
    vertices.push_back(vert36);
}
