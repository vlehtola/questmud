inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
set_class(3);
set_sub_type("sabre");
set_name("sabre");
set_short("A short sabre");
set_long("You can see some dried stains of blood on the blade.\n"+
         "Someone or something has probably bruised a wound\n"+
        "or two with this, though the blade seems to in fine\n"+
        "condition. Handle is made from some yellow mineral,\n"+
        "but it doesn't seem to be gold.\n");
}
