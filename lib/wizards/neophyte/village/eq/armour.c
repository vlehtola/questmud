inherit "obj/armour";
int i;
start() {
        i = random(4);
        if(i==0) {
        set_class(random(1)+1);
        set_sub_type("leather coat");
        return 1;
}
if(i==1) {
        set_class(random(1)+1);
        set_sub_type("leather armour");
return 1;
}
if(i==2) {
        set_class(random(1)+1);
        set_sub_type("banded mail");
return 1;
}
if(i==3) {
        set_class(random(1)+1);
        set_sub_type("chain mail");
return 1;
}
set_class(random(1)+1);
set_sub_type("scale mail");
return 1;
}
