inherit "/wizards/walla/ravenloft/outworld/outroom"; 
 
short() {
    return "Plains";
}
 
long() {
    write("All you can see, are plains as far as the eye reaches.\n");
    if (this_player()->query_wiz()) {
        write("Coordinates: " + coordinate_x + "," + coordinate_y + "\n");
    }
    if (!find_object("/wizards/walla/ravenloft/outworld/map")) {
        write("OBJECT NOT FOUND!\n");
        return 0;
    }
  find_object("/wizards/walla/ravenloft/outworld/map")->draw_map(coordinate_x,coordinate_y);
    return 1;
}
 
can_put_and_get(str) {
    return 1;
}
