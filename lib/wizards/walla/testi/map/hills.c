inherit "wizards/walla/testi/map/outroom";

short() {
    return "Grass covered hills";
}

long() {
    write("You are walking on green, grass covered hills.\n");
    if (this_player()->query_wiz()) {
        write("Coordinates: " + coordinate_x + "," + coordinate_y + "\n");
    }
    if (!find_object("/wizards/walla/testi/map/map")) {
        write("OBJECT NOT FOUND!\n");
        return 0;
    }
find_object("/wizards/walla/testi/map/map")->draw_map(coordinate_x,coordinate_y);
 return 1;
}

can_put_and_get(str) {
    return 1;
}


