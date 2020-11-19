ArrayList<Rectangle_Class> r;

void setup(){
  size(600,400);
  r = new ArrayList<Rectangle_Class>();
  // int i;
  for (int i=0; i<10; i++){
    r.add(new Rectangle_Class(width, height));
  }
  // println(i);
  
}

void draw(){
  background(0);
  for (int i=0; i<10; i++){
    r.get(i).draw_myself();
  }
}

void mouseClicked(){
  for (int i=0; i<10; i++){
    r.get(i).check_if_clicked(mouseX, mouseY);
  }
}

// r.get(i).draw_myself() -> in python: r[i].draw_myself()
