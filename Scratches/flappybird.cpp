#include <iostream>
#include <vector>

using namespace std;

class Bird {
public:
  int x;
  int y;
  int velocity;

  Bird() {
    x = 100;
    y = 100;
    velocity = 0;
  }

  void move() {
    x += velocity;
  }

  void flap() {
    velocity += 10;
  }

  void draw() {
    cout << "Bird at (" << x << ", " << y << ")" << endl;
  }
};

class Pipe {
public:
  int x;
  int y;
  int height;

  Pipe() {
    x = 200;
    y = 0;
    height = 100;
  }

  void move() {
    x -= 5;
  }

  void draw() {
    cout << "Pipe at (" << x << ", " << y << ")" << endl;
  }
};

int main() {
  Bird bird;
  vector<Pipe> pipes;

  while (true) {
    // Move the bird
    bird.move();

    // Move the pipes
    for (int i = 0; i < pipes.size(); i++) {
      pipes[i].move();
    }

    // Check for collisions
    for (int i = 0; i < pipes.size(); i++) {
      if (bird.x >= pipes[i].x && bird.x <= pipes[i].x + 50 && bird.y >= pipes[i].y && bird.y <= pipes[i].y + pipes[i].height) {
        cout << "Game over!" << endl;
        return 0;
      }
    }

    // Draw the bird and pipes
    bird.draw();
    for (int i = 0; i < pipes.size(); i++) {
      pipes[i].draw();
    }

    // Wait for a key press
    char key;
    cin >> key;

    // If the spacebar is pressed, flap the bird's wings
    if (key == ' ') {
      bird.flap();
    }
  }
}
