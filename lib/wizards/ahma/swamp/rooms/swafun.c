int mode, tmp, norepeat;

mode1() {
  remove_exit("north");
  remove_exit("south");
  remove_exit("west");
  remove_exit("east");
  mode = 0;
  reset();
  call_out("message", 1);
}

mode2() {
  mode = 1;
  reset();
  call_out("message", 1);
}

mode3() {
  mode = 2;
  reset();
  call_out("message", 1);
}

message() {
  tell_room(this_object(), "****Room mode changed.****\n");
}

callfirst() {
  "/wizards/ahma/swamp/rooms/swa1d"->mode2();
  "/wizards/ahma/swamp/rooms/swa1f"->mode2();
  "/wizards/ahma/swamp/rooms/swa2a"->mode2();
  "/wizards/ahma/swamp/rooms/swa2c"->mode2();
  "/wizards/ahma/swamp/rooms/swa2d"->mode2();
  "/wizards/ahma/swamp/rooms/swa2e"->mode2();
  "/wizards/ahma/swamp/rooms/swa2f"->mode2();
  "/wizards/ahma/swamp/rooms/swa3a"->mode2();
  "/wizards/ahma/swamp/rooms/swa3c"->mode2();
  "/wizards/ahma/swamp/rooms/swa3d"->mode2();
  "/wizards/ahma/swamp/rooms/swa3d"->set_firstdone();
  "/wizards/ahma/swamp/rooms/swa3e"->mode2();
  "/wizards/ahma/swamp/rooms/swa3f"->mode2();
  "/wizards/ahma/swamp/rooms/swa4c"->mode2();
  "/wizards/ahma/swamp/rooms/swa4d"->mode2();
}

callsecond() {
  "/wizards/ahma/swamp/rooms/swa3d"->mode3();
  "/wizards/ahma/swamp/rooms/swa6b"->mode3();
  "/wizards/ahma/swamp/rooms/swa3e"->mode3();
  "/wizards/ahma/swamp/rooms/swa2f"->mode3();
  "/wizards/ahma/swamp/rooms/swa6b"->set_seconddone();
  "/wizards/ahma/swamp/rooms/swa3e"->set_seconddone();
  "/wizards/ahma/swamp/rooms/swa2f"->set_seconddone();
}

thirdmore() {
  tmp++;
}

thirdless() {
  tmp--;
}

thirdcheck() {
  if(tmp != 2) {
    "/wizards/ahma/swamp/rooms/swa6b"->remove_tmp();
    "/wizards/ahma/swamp/rooms/swa3e"->remove_tmp();
  return 1;
  }
  if(!norepeat) {
    "/wizards/ahma/swamp/rooms/swa6b"->set_alldone();
    "/wizards/ahma/swamp/rooms/swa3e"->set_alldone();
    norepeat++;
    call_out("callthird", 5);
  }
}

callthird() {
  "/wizards/ahma/swamp/rooms/swa6f"->thirddone();
  "/wizards/ahma/swamp/rooms/spec3"->thirddone();
}