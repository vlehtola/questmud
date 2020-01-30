inherit "wizards/celtron/park/outroom";

short() {
    return "Long grass";
}

reset() {
    if(random(3) == 0) {
move_object(clone_object("/wizards/celtron/forest/ugly_orc"),this_object());
    }
}

long() {
    write("You stand on a clear grass-covered area.\n");
    if (this_player()->query_wiz()) {
    	write("Coordinates: " + coordinate_x + "," + coordinate_y + "\n");
    }
    if (!find_object("/wizards/celtron/park/map")) {
        write("OBJECT NOT FOUND!\n");
        return 0;
    }
find_object("/wizards/celtron/park/map")->draw_map(coordinate_x,coordinate_y);
    return 1;
}

can_put_and_get(str) {
    return 1;
}









