inherit "/wizards/celtron/forest/outroom";

short() {
    return "Dense bushes";
}

long() {
    write("You are in the middle of dense bushes.\n");
    if (this_player()->query_wiz()) {
    	write("Coordinates: " + coordinate_x + "," + coordinate_y + "\n");
    }
    if (!find_object("/wizards/celtron/forest/map")) {
        write("OBJECT NOT FOUND!\n");
        return 0;
    }
  find_object("/wizards/celtron/forest/map")->draw_map(coordinate_x,coordinate_y);
    return 1;
}

can_put_and_get(str) {
    return 1;
}









