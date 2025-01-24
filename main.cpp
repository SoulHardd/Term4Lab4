#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <stdexcept>

class OrientedGraph {
public:
    struct Vertex {
        size_t id;
        int value;
        std::vector<std::pair<size_t, int>> edges; // pair<destination, weight>
    };

    void AddVertex(size_t id, int value) {
        vertices.push_back({id, value});
    }

    void AddEdge(size_t from, size_t to, int weight) {
        auto it = std::find_if(vertices.begin(), vertices.end(), [from](const Vertex& v) { return v.id == from; });
        if (it != vertices.end()) {
            it->edges.emplace_back(to, weight);
        } else {
            throw std::runtime_error("Vertex not found");
        }
    }

    const std::vector<Vertex>& GetAllVertices() const {
        return vertices;
    }

private:
    std::vector<Vertex> vertices;
};

class GraphWindow {
public:
    GraphWindow() : window(sf::VideoMode(800, 600), "Graph Visualization") {
        if (!font.loadFromFile("arial.ttf")) {
            throw std::runtime_error("Could not load font");
        }
    }

    void run() {
        while (window.isOpen()) {
            handleEvents();
            window.clear(sf::Color(240, 242, 245));
            drawGraph();
            window.display();
        }
    }

private:
    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    handleMouseClick(event.mouseButton.x, event.mouseButton.y);
                }
            }
        }
    }

    void handleMouseClick(int x, int y) {
        // Implement logic to add vertex or edit vertex data
        // This is a placeholder for the actual implementation
        std::cout << "Mouse clicked at: " << x << ", " << y << std::endl;
    }

    void drawGraph() {
        const auto& vertices = graph.GetAllVertices();
        float radius = 25.0f;
        float angleStep = 2 * 3.14159f / vertices.size();

        for (size_t i = 0; i < vertices.size(); ++i) {
            float angle = i * angleStep;
            float x = 400 + radius * std::cos(angle);
            float y = 300 + radius * std::sin(angle);

            sf::CircleShape circle(25);
            circle.setPosition(x - 25, y - 25);
            circle.setFillColor(sf::Color(100, 149, 237));
            window.draw(circle);

            sf::Text text;
            text.setFont(font);
            text.setString(std::to_string(vertices[i].id) + ": " + std::to_string(vertices[i].value));
            text.setCharacterSize(12);
            text.setFillColor(sf::Color::White);
            text.setPosition(x - 20, y - 10);
            window.draw(text);
        }

        drawEdges();
    }

    void drawEdges() {
        const auto& vertices = graph.GetAllVertices();
        for (const auto& vertex : vertices) {
            for (const auto& edge : vertex.edges) {
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(400, 300), sf::Color::Red),
                    sf::Vertex(sf::Vector2f(400, 300), sf::Color::Red)
                };

                // Calculate positions based on vertex id (this is a placeholder)
                float angle = vertex.id * (2 * 3.14159f / vertices.size());
                float xFrom = 400 + 200 * std::cos(angle);
                float yFrom = 300 + 200 * std::sin(angle);

                // Find the destination vertex
                auto it = std::find_if(vertices.begin(), vertices.end(), [&](const OrientedGraph::Vertex& v) {
                    return v.id == edge.first; // edge.first is the destination id
                });

                if (it != vertices.end()) {
                    float angleTo = it->id * (2 * 3.14159f / vertices.size());
                    float xTo = 400 + 200 * std::cos(angleTo);
                    float yTo = 300 + 200 * std::sin(angleTo);

                    line[0].position = sf::Vector2f(xFrom, yFrom);
                    line[1].position = sf::Vector2f(xTo, yTo);

                    window.draw(line, 2, sf::Lines);
                }
            }
        }
    }

    sf::RenderWindow window;
    OrientedGraph graph;
    sf::Font font;
};

int main() {
    try {
        GraphWindow graphWindow;
        graphWindow.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}