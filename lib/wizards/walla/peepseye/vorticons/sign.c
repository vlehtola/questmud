short() { return "A rotten sign, lying on the floor"; } 
 
long(str) {
    write("The sign has been set here by the kind pirates of Pepe's Eye Point. It reads:\n");
    write("'Thisse is the place of them Vorticons. Go home now'.\n");
    write("'There are horrible things ahead and no one has ever come back from that maze'.\n");
    write("'If you choose to continue your journey, may the Lord be with ye'.\n");
    write("'To git oute, lite a lantern somewhere in thise maze'.\n");  
  return;
}
 
id(str) { return str == "sign"; }
 
get(str) {
    if (str == "sign") {
        write("You can't take the sign.\n");
        return 0;
 }                   
    return 0;
}

