public class Key {
    private String direction; // left right down up , ...
    private String type; // goal or movable key
    private Point point;    // point in Coordinate plane
    
    private final String color; 
    private final String owner;

    public Key(String type, String direction, Point point, String color, String owner) {
        this.direction = direction;
        this.type = type;
        this.point = point;
        this.color = color;
        this.owner = owner;
    }
    

    public String getDirection() {
        return direction;
    }

    public void setDirection(String direction) {
        this.direction = direction;
    }

    public String getType() {
        return type;
    }

    public Point getPoint() {
        return point;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getColor() {
        return color;
    }

    public String getOwner() {
        return owner;
    }
    
    public boolean equals(Key key){
        return (color.equals(key.color) && direction.equals(key.direction) && owner.equals(key.owner) && point.equals(key.point) && type.equals(key.type));
    }
    
}
