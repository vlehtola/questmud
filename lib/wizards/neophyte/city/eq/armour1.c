inherit "obj/armour";
int i;
start() {
        i = random(9);
        if(i==0) {
        set_class(random(2)+1);
        set_sub_type("chain coif");
        return 1;
}
if(i==1) {
        set_class(random(2)+1);
        set_sub_type("cap");
return 1;
}
if(i==2) {
        set_class(random(2)+1);
        set_sub_type("leather gloves");
return 1;
}
if(i==3) {
        set_class(random(2)+1);
        set_sub_type("leather gauntlets");
return 1;
}
if(i==4) {
        set_class(random(2)+1);
        set_sub_type("leather bracers");
return 1;
}
if(i==5) {
        set_class(random(2)+1);
        set_sub_type("bracers");
return 1;
}
if(i==6) {
        set_class(random(2)+1);
        set_sub_type("leather boots");
return 1;
}
if(i==7) {
        set_class(random(2)+1);
        set_sub_type("boots");
return 1;
}
if(i==8) {
        set_class(random(2)+1);
        set_sub_type("leather leggings");
return 1;
}
if(i==9) {
        set_class(random(2)+1);
        set_sub_type("leggings");
return 1;
}
set_class(random(2)+1);
set_sub_type("arm guards");
return 1;
}
