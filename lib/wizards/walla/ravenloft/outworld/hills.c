inherit "/wizards/walla/ravenloft/outworld/outroom"; 
 
short() {
    return "Hills";
}
 
long() {
    write("You are on top of a small hill. Before you, you discover a magnitude of similar ones.\n");
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
