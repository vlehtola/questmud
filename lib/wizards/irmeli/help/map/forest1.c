inherit "wizards/celtron/forest/outroom";

short() {
    return "Light forest";
}

long() {
    write("You are walking in a light forest.\n");
    write("There are some trees here and there.\n");
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









