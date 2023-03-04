class Point:
    def __init__(self, xCoor, yCoor):
        self.x = xCoor
        self.y = yCoor

    def coordinates(self):
        return (self.x, self.y)

    def moveTo(self, xCoor, yCoor):
        self.x = xCoor
        self.y = yCoor

    def move(self, deltaX, deltaY):
        self.x += deltaX
        self.y += deltaY

    def distanceTo(self, other):
        vert = other.y - self.y
        horz = other.x - self.x
        return (vert**2 + horz**2)**(1/2)


origin = Point(0, 0)
print(Point.coordinates())
