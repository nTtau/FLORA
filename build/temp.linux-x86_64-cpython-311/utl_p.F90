module CodeInfo
  save
  integer(kind=8):: logunit
  character(len=128):: cmdline0
  character(len=128):: codename
  character(len=8):: codedate
  character(len=8):: codetime
  character(len=8):: rundate
  character(len=8):: runtime
  character(len=8):: runnode
  character(len=80):: probid
  data probid/" "/
  character(len=80):: note
  data note/" "/
  character(len=13):: code_ts
  data code_ts/" "/
  character(len=28):: run_ts
  character(len=80):: session
  data session/" "/
end module CodeInfo
module CommandLine
  save
  integer(kind=8):: debug_=0
  integer(kind=8):: echo_=0
  integer(kind=8):: verbose_=0
  character(len=32):: probname_
  data probname_/"untitled"/
end module CommandLine
subroutine utlpasspointers()
  use CodeInfo
  use CommandLine
  call utlgrabscalarpointers_integer(int(0, kind=8), logunit)
  call utlgrabscalarpointers_integer(int(1, kind=8), debug_)
  call utlgrabscalarpointers_integer(int(2, kind=8), echo_)
  call utlgrabscalarpointers_integer(int(3, kind=8), verbose_)
  call utlgrabarraypointers_character(int(0, kind=8), cmdline0)
  call utlgrabarraypointers_character(int(1, kind=8), codename)
  call utlgrabarraypointers_character(int(2, kind=8), codedate)
  call utlgrabarraypointers_character(int(3, kind=8), codetime)
  call utlgrabarraypointers_character(int(4, kind=8), rundate)
  call utlgrabarraypointers_character(int(5, kind=8), runtime)
  call utlgrabarraypointers_character(int(6, kind=8), runnode)
  call utlgrabarraypointers_character(int(7, kind=8), probid)
  call utlgrabarraypointers_character(int(8, kind=8), note)
  call utlgrabarraypointers_character(int(9, kind=8), code_ts)
  call utlgrabarraypointers_character(int(10, kind=8), run_ts)
  call utlgrabarraypointers_character(int(11, kind=8), session)
  call utlgrabarraypointers_character(int(12, kind=8), probname_)
  return
end
subroutine utlnullifypointers()
  use CodeInfo
  use CommandLine
  return
end
