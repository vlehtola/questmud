inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
set_class(1);
set_sub_type("dagger");
set_name("dagger");
set_short("An ugly orcish dagger");
set_long("This dagger is probably the shittiest one you've ever seen.\n"+
        "You have heard that weapons manufactured by orcs are crap,\n"+
        "but this so called weapon takes that definition to a totally\n"+
        "new level. Handle looks like it's made from moldy bread and\n"+
        "the not-so-sharp blade couldn't probably cut a piece of paper.\n");
}
