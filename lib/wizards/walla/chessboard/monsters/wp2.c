inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(13+random(10));
    set_name("pawn");
    set_alias("pawn");
    set_short("A white pawn of the chessboard");
    set_long("This pawn stands straight up and doesn't seem to move.\n" +
             "He stands in the front row.\n");
    set_al(-90);
    
}
