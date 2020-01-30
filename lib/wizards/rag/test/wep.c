inherit "obj/weapon";

start() {
  set_class(9);
  set_sub_type("broad sword");
  set_short("Special weapon");
}

hit() {
        if(!wielded_by) return;

        if(wielded_by->query_right_weapon() == this_object()) {
                write("Right hit from ");
        }
        if(wielded_by->query_left_weapon() == this_object()) {
                write("Left hit from ");
        }
        write(file_name(previous_object())+"\n");
        return;
}
