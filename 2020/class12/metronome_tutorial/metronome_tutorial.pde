float ms_rhythm = 1000.;

float prev_time = 0.;

int counter = 0;

int rhythm_44[] = {2,0,1,0}; // rhythm with index 0
int rhythm_78[] = {2,0,0,1,0,1,0}; // rhythm with index 1

ArrayList< int[] > rhythms = new ArrayList<int[]>();
float denominators[] = {4. , 8.};
int numerators[] = {4 , 7};

int selected_idx = 1;

void setup(){
  background(0);
  rhythms.add(rhythm_44);
  rhythms.add(rhythm_78);
}

void draw(){
  float curr_time = millis();
  if( prev_time <= curr_time - ms_rhythm*(4./denominators[selected_idx]) ){
    // println( str(counter++) + " - " + curr_time );
    println( rhythms.get(selected_idx)[ counter++ ] );
    counter = counter%numerators[selected_idx];
    prev_time += ms_rhythm*(4./denominators[selected_idx]);
  }
}
