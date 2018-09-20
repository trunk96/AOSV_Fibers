
main:     formato del file elf64-x86-64


Disassemblamento della sezione .interp:

0000000000000238 <.interp>:
 238:	2f                   	(bad)  
 239:	6c                   	insb   (%dx),%es:(%rdi)
 23a:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
 241:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
 246:	78 2d                	js     275 <_init-0x493>
 248:	78 38                	js     282 <_init-0x486>
 24a:	36 2d 36 34 2e 73    	ss sub $0x732e3436,%eax
 250:	6f                   	outsl  %ds:(%rsi),(%dx)
 251:	2e 32 00             	xor    %cs:(%rax),%al

Disassemblamento della sezione .note.ABI-tag:

0000000000000254 <.note.ABI-tag>:
 254:	04 00                	add    $0x0,%al
 256:	00 00                	add    %al,(%rax)
 258:	10 00                	adc    %al,(%rax)
 25a:	00 00                	add    %al,(%rax)
 25c:	01 00                	add    %eax,(%rax)
 25e:	00 00                	add    %al,(%rax)
 260:	47                   	rex.RXB
 261:	4e 55                	rex.WRX push %rbp
 263:	00 00                	add    %al,(%rax)
 265:	00 00                	add    %al,(%rax)
 267:	00 03                	add    %al,(%rbx)
 269:	00 00                	add    %al,(%rax)
 26b:	00 02                	add    %al,(%rdx)
 26d:	00 00                	add    %al,(%rax)
 26f:	00 00                	add    %al,(%rax)
 271:	00 00                	add    %al,(%rax)
	...

Disassemblamento della sezione .note.gnu.build-id:

0000000000000274 <.note.gnu.build-id>:
 274:	04 00                	add    $0x0,%al
 276:	00 00                	add    %al,(%rax)
 278:	14 00                	adc    $0x0,%al
 27a:	00 00                	add    %al,(%rax)
 27c:	03 00                	add    (%rax),%eax
 27e:	00 00                	add    %al,(%rax)
 280:	47                   	rex.RXB
 281:	4e 55                	rex.WRX push %rbp
 283:	00 b4 e4 51 b3 30 a0 	add    %dh,-0x5fcf4caf(%rsp,%riz,8)
 28a:	02 b1 fc dd 76 1e    	add    0x1e76ddfc(%rcx),%dh
 290:	7f a5                	jg     237 <_init-0x4d1>
 292:	32 d0                	xor    %al,%dl
 294:	6f                   	outsl  %ds:(%rsi),(%dx)
 295:	f3 22 eb             	repz and %bl,%ch

Disassemblamento della sezione .gnu.hash:

0000000000000298 <.gnu.hash>:
 298:	01 00                	add    %eax,(%rax)
 29a:	00 00                	add    %al,(%rax)
 29c:	01 00                	add    %eax,(%rax)
 29e:	00 00                	add    %al,(%rax)
 2a0:	01 00                	add    %eax,(%rax)
	...

Disassemblamento della sezione .dynsym:

00000000000002b8 <.dynsym>:
	...
 2d0:	89 00                	mov    %eax,(%rax)
 2d2:	00 00                	add    %al,(%rax)
 2d4:	20 00                	and    %al,(%rax)
	...
 2e6:	00 00                	add    %al,(%rax)
 2e8:	10 00                	adc    %al,(%rax)
 2ea:	00 00                	add    %al,(%rax)
 2ec:	12 00                	adc    (%rax),%al
	...
 2fe:	00 00                	add    %al,(%rax)
 300:	15 00 00 00 12       	adc    $0x12000000,%eax
	...
 315:	00 00                	add    %al,(%rax)
 317:	00 26                	add    %ah,(%rsi)
 319:	00 00                	add    %al,(%rax)
 31b:	00 12                	add    %dl,(%rdx)
	...
 32d:	00 00                	add    %al,(%rax)
 32f:	00 47 00             	add    %al,0x0(%rdi)
 332:	00 00                	add    %al,(%rax)
 334:	12 00                	adc    (%rax),%al
	...
 346:	00 00                	add    %al,(%rax)
 348:	3b 00                	cmp    (%rax),%eax
 34a:	00 00                	add    %al,(%rax)
 34c:	12 00                	adc    (%rax),%al
	...
 35e:	00 00                	add    %al,(%rax)
 360:	61                   	(bad)  
 361:	00 00                	add    %al,(%rax)
 363:	00 12                	add    %dl,(%rdx)
	...
 375:	00 00                	add    %al,(%rax)
 377:	00 a5 00 00 00 20    	add    %ah,0x20000000(%rbp)
	...
 38d:	00 00                	add    %al,(%rax)
 38f:	00 34 00             	add    %dh,(%rax,%rax,1)
 392:	00 00                	add    %al,(%rax)
 394:	12 00                	adc    (%rax),%al
	...
 3a6:	00 00                	add    %al,(%rax)
 3a8:	40 00 00             	add    %al,(%rax)
 3ab:	00 12                	add    %dl,(%rdx)
	...
 3bd:	00 00                	add    %al,(%rax)
 3bf:	00 4d 00             	add    %cl,0x0(%rbp)
 3c2:	00 00                	add    %al,(%rax)
 3c4:	12 00                	adc    (%rax),%al
	...
 3d6:	00 00                	add    %al,(%rax)
 3d8:	2d 00 00 00 12       	sub    $0x12000000,%eax
	...
 3ed:	00 00                	add    %al,(%rax)
 3ef:	00 0b                	add    %cl,(%rbx)
 3f1:	00 00                	add    %al,(%rax)
 3f3:	00 12                	add    %dl,(%rdx)
	...
 405:	00 00                	add    %al,(%rax)
 407:	00 b4 00 00 00 20 00 	add    %dh,0x200000(%rax,%rax,1)
	...
 41e:	00 00                	add    %al,(%rax)
 420:	52                   	push   %rdx
 421:	00 00                	add    %al,(%rax)
 423:	00 22                	add    %ah,(%rdx)
	...

Disassemblamento della sezione .dynstr:

0000000000000438 <.dynstr>:
 438:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
 43c:	63 2e                	movslq (%rsi),%ebp
 43e:	73 6f                	jae    4af <_init-0x259>
 440:	2e 36 00 65 78       	cs add %ah,%ss:0x78(%rbp)
 445:	69 74 00 70 75 74 73 	imul   $0x737475,0x70(%rax,%rax,1),%esi
 44c:	00 
 44d:	5f                   	pop    %rdi
 44e:	5f                   	pop    %rdi
 44f:	73 74                	jae    4c5 <_init-0x243>
 451:	61                   	(bad)  
 452:	63 6b 5f             	movslq 0x5f(%rbx),%ebp
 455:	63 68 6b             	movslq 0x6b(%rax),%ebp
 458:	5f                   	pop    %rdi
 459:	66 61                	data16 (bad) 
 45b:	69 6c 00 70 72 69 6e 	imul   $0x746e6972,0x70(%rax,%rax,1),%ebp
 462:	74 
 463:	66 00 73 74          	data16 add %dh,0x74(%rbx)
 467:	72 74                	jb     4dd <_init-0x22b>
 469:	6f                   	outsl  %ds:(%rsi),(%dx)
 46a:	6b 00 73             	imul   $0x73,(%rax),%eax
 46d:	74 72                	je     4e1 <_init-0x227>
 46f:	74 6f                	je     4e0 <_init-0x228>
 471:	6c                   	insb   (%dx),%es:(%rdi)
 472:	00 72 65             	add    %dh,0x65(%rdx)
 475:	61                   	(bad)  
 476:	64 00 6d 61          	add    %ch,%fs:0x61(%rbp)
 47a:	6c                   	insb   (%dx),%es:(%rdi)
 47b:	6c                   	insb   (%dx),%es:(%rdi)
 47c:	6f                   	outsl  %ds:(%rsi),(%dx)
 47d:	63 00                	movslq (%rax),%eax
 47f:	69 6f 63 74 6c 00 6f 	imul   $0x6f006c74,0x63(%rdi),%ebp
 486:	70 65                	jo     4ed <_init-0x21b>
 488:	6e                   	outsb  %ds:(%rsi),(%dx)
 489:	00 5f 5f             	add    %bl,0x5f(%rdi)
 48c:	63 78 61             	movslq 0x61(%rax),%edi
 48f:	5f                   	pop    %rdi
 490:	66 69 6e 61 6c 69    	imul   $0x696c,0x61(%rsi),%bp
 496:	7a 65                	jp     4fd <_init-0x20b>
 498:	00 5f 5f             	add    %bl,0x5f(%rdi)
 49b:	6c                   	insb   (%dx),%es:(%rdi)
 49c:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
 4a3:	72 74                	jb     519 <_init-0x1ef>
 4a5:	5f                   	pop    %rdi
 4a6:	6d                   	insl   (%dx),%es:(%rdi)
 4a7:	61                   	(bad)  
 4a8:	69 6e 00 47 4c 49 42 	imul   $0x42494c47,0x0(%rsi),%ebp
 4af:	43 5f                	rex.XB pop %r15
 4b1:	32 2e                	xor    (%rsi),%ch
 4b3:	34 00                	xor    $0x0,%al
 4b5:	47                   	rex.RXB
 4b6:	4c                   	rex.WR
 4b7:	49                   	rex.WB
 4b8:	42                   	rex.X
 4b9:	43 5f                	rex.XB pop %r15
 4bb:	32 2e                	xor    (%rsi),%ch
 4bd:	32 2e                	xor    (%rsi),%ch
 4bf:	35 00 5f 49 54       	xor    $0x54495f00,%eax
 4c4:	4d 5f                	rex.WRB pop %r15
 4c6:	64 65 72 65          	fs gs jb 52f <_init-0x1d9>
 4ca:	67 69 73 74 65 72 54 	imul   $0x4d547265,0x74(%ebx),%esi
 4d1:	4d 
 4d2:	43 6c                	rex.XB insb (%dx),%es:(%rdi)
 4d4:	6f                   	outsl  %ds:(%rsi),(%dx)
 4d5:	6e                   	outsb  %ds:(%rsi),(%dx)
 4d6:	65 54                	gs push %rsp
 4d8:	61                   	(bad)  
 4d9:	62                   	(bad)  
 4da:	6c                   	insb   (%dx),%es:(%rdi)
 4db:	65 00 5f 5f          	add    %bl,%gs:0x5f(%rdi)
 4df:	67 6d                	insl   (%dx),%es:(%edi)
 4e1:	6f                   	outsl  %ds:(%rsi),(%dx)
 4e2:	6e                   	outsb  %ds:(%rsi),(%dx)
 4e3:	5f                   	pop    %rdi
 4e4:	73 74                	jae    55a <_init-0x1ae>
 4e6:	61                   	(bad)  
 4e7:	72 74                	jb     55d <_init-0x1ab>
 4e9:	5f                   	pop    %rdi
 4ea:	5f                   	pop    %rdi
 4eb:	00 5f 49             	add    %bl,0x49(%rdi)
 4ee:	54                   	push   %rsp
 4ef:	4d 5f                	rex.WRB pop %r15
 4f1:	72 65                	jb     558 <_init-0x1b0>
 4f3:	67 69 73 74 65 72 54 	imul   $0x4d547265,0x74(%ebx),%esi
 4fa:	4d 
 4fb:	43 6c                	rex.XB insb (%dx),%es:(%rdi)
 4fd:	6f                   	outsl  %ds:(%rsi),(%dx)
 4fe:	6e                   	outsb  %ds:(%rsi),(%dx)
 4ff:	65 54                	gs push %rsp
 501:	61                   	(bad)  
 502:	62                   	.byte 0x62
 503:	6c                   	insb   (%dx),%es:(%rdi)
 504:	65                   	gs
	...

Disassemblamento della sezione .gnu.version:

0000000000000506 <.gnu.version>:
 506:	00 00                	add    %al,(%rax)
 508:	00 00                	add    %al,(%rax)
 50a:	02 00                	add    (%rax),%al
 50c:	03 00                	add    (%rax),%eax
 50e:	02 00                	add    (%rax),%al
 510:	02 00                	add    (%rax),%al
 512:	02 00                	add    (%rax),%al
 514:	02 00                	add    (%rax),%al
 516:	00 00                	add    %al,(%rax)
 518:	02 00                	add    (%rax),%al
 51a:	02 00                	add    (%rax),%al
 51c:	02 00                	add    (%rax),%al
 51e:	02 00                	add    (%rax),%al
 520:	02 00                	add    (%rax),%al
 522:	00 00                	add    %al,(%rax)
 524:	02 00                	add    (%rax),%al

Disassemblamento della sezione .gnu.version_r:

0000000000000528 <.gnu.version_r>:
 528:	01 00                	add    %eax,(%rax)
 52a:	02 00                	add    (%rax),%al
 52c:	01 00                	add    %eax,(%rax)
 52e:	00 00                	add    %al,(%rax)
 530:	10 00                	adc    %al,(%rax)
 532:	00 00                	add    %al,(%rax)
 534:	00 00                	add    %al,(%rax)
 536:	00 00                	add    %al,(%rax)
 538:	14 69                	adc    $0x69,%al
 53a:	69 0d 00 00 03 00 73 	imul   $0x73,0x30000(%rip),%ecx        # 30544 <__FRAME_END__+0x2ed40>
 541:	00 00 00 
 544:	10 00                	adc    %al,(%rax)
 546:	00 00                	add    %al,(%rax)
 548:	75 1a                	jne    564 <_init-0x1a4>
 54a:	69 09 00 00 02 00    	imul   $0x20000,(%rcx),%ecx
 550:	7d 00                	jge    552 <_init-0x1b6>
 552:	00 00                	add    %al,(%rax)
 554:	00 00                	add    %al,(%rax)
	...

Disassemblamento della sezione .rela.dyn:

0000000000000558 <.rela.dyn>:
 558:	70 1d                	jo     577 <_init-0x191>
 55a:	20 00                	and    %al,(%rax)
 55c:	00 00                	add    %al,(%rax)
 55e:	00 00                	add    %al,(%rax)
 560:	08 00                	or     %al,(%rax)
 562:	00 00                	add    %al,(%rax)
 564:	00 00                	add    %al,(%rax)
 566:	00 00                	add    %al,(%rax)
 568:	e0 08                	loopne 572 <_init-0x196>
 56a:	00 00                	add    %al,(%rax)
 56c:	00 00                	add    %al,(%rax)
 56e:	00 00                	add    %al,(%rax)
 570:	78 1d                	js     58f <_init-0x179>
 572:	20 00                	and    %al,(%rax)
 574:	00 00                	add    %al,(%rax)
 576:	00 00                	add    %al,(%rax)
 578:	08 00                	or     %al,(%rax)
 57a:	00 00                	add    %al,(%rax)
 57c:	00 00                	add    %al,(%rax)
 57e:	00 00                	add    %al,(%rax)
 580:	a0 08 00 00 00 00 00 	movabs 0x800000000000008,%al
 587:	00 08 
 589:	20 20                	and    %ah,(%rax)
 58b:	00 00                	add    %al,(%rax)
 58d:	00 00                	add    %al,(%rax)
 58f:	00 08                	add    %cl,(%rax)
 591:	00 00                	add    %al,(%rax)
 593:	00 00                	add    %al,(%rax)
 595:	00 00                	add    %al,(%rax)
 597:	00 08                	add    %cl,(%rax)
 599:	20 20                	and    %ah,(%rax)
 59b:	00 00                	add    %al,(%rax)
 59d:	00 00                	add    %al,(%rax)
 59f:	00 d8                	add    %bl,%al
 5a1:	1f                   	(bad)  
 5a2:	20 00                	and    %al,(%rax)
 5a4:	00 00                	add    %al,(%rax)
 5a6:	00 00                	add    %al,(%rax)
 5a8:	06                   	(bad)  
 5a9:	00 00                	add    %al,(%rax)
 5ab:	00 01                	add    %al,(%rcx)
	...
 5b5:	00 00                	add    %al,(%rax)
 5b7:	00 e0                	add    %ah,%al
 5b9:	1f                   	(bad)  
 5ba:	20 00                	and    %al,(%rax)
 5bc:	00 00                	add    %al,(%rax)
 5be:	00 00                	add    %al,(%rax)
 5c0:	06                   	(bad)  
 5c1:	00 00                	add    %al,(%rax)
 5c3:	00 07                	add    %al,(%rdi)
	...
 5cd:	00 00                	add    %al,(%rax)
 5cf:	00 e8                	add    %ch,%al
 5d1:	1f                   	(bad)  
 5d2:	20 00                	and    %al,(%rax)
 5d4:	00 00                	add    %al,(%rax)
 5d6:	00 00                	add    %al,(%rax)
 5d8:	06                   	(bad)  
 5d9:	00 00                	add    %al,(%rax)
 5db:	00 08                	add    %cl,(%rax)
	...
 5e5:	00 00                	add    %al,(%rax)
 5e7:	00 f0                	add    %dh,%al
 5e9:	1f                   	(bad)  
 5ea:	20 00                	and    %al,(%rax)
 5ec:	00 00                	add    %al,(%rax)
 5ee:	00 00                	add    %al,(%rax)
 5f0:	06                   	(bad)  
 5f1:	00 00                	add    %al,(%rax)
 5f3:	00 0e                	add    %cl,(%rsi)
	...
 5fd:	00 00                	add    %al,(%rax)
 5ff:	00 f8                	add    %bh,%al
 601:	1f                   	(bad)  
 602:	20 00                	and    %al,(%rax)
 604:	00 00                	add    %al,(%rax)
 606:	00 00                	add    %al,(%rax)
 608:	06                   	(bad)  
 609:	00 00                	add    %al,(%rax)
 60b:	00 0f                	add    %cl,(%rdi)
	...

Disassemblamento della sezione .rela.plt:

0000000000000618 <.rela.plt>:
 618:	88 1f                	mov    %bl,(%rdi)
 61a:	20 00                	and    %al,(%rax)
 61c:	00 00                	add    %al,(%rax)
 61e:	00 00                	add    %al,(%rax)
 620:	07                   	(bad)  
 621:	00 00                	add    %al,(%rax)
 623:	00 02                	add    %al,(%rdx)
	...
 62d:	00 00                	add    %al,(%rax)
 62f:	00 90 1f 20 00 00    	add    %dl,0x201f(%rax)
 635:	00 00                	add    %al,(%rax)
 637:	00 07                	add    %al,(%rdi)
 639:	00 00                	add    %al,(%rax)
 63b:	00 03                	add    %al,(%rbx)
	...
 645:	00 00                	add    %al,(%rax)
 647:	00 98 1f 20 00 00    	add    %bl,0x201f(%rax)
 64d:	00 00                	add    %al,(%rax)
 64f:	00 07                	add    %al,(%rdi)
 651:	00 00                	add    %al,(%rax)
 653:	00 04 00             	add    %al,(%rax,%rax,1)
	...
 65e:	00 00                	add    %al,(%rax)
 660:	a0 1f 20 00 00 00 00 	movabs 0x70000000000201f,%al
 667:	00 07 
 669:	00 00                	add    %al,(%rax)
 66b:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 671 <_init-0x97>
 671:	00 00                	add    %al,(%rax)
 673:	00 00                	add    %al,(%rax)
 675:	00 00                	add    %al,(%rax)
 677:	00 a8 1f 20 00 00    	add    %ch,0x201f(%rax)
 67d:	00 00                	add    %al,(%rax)
 67f:	00 07                	add    %al,(%rdi)
 681:	00 00                	add    %al,(%rax)
 683:	00 06                	add    %al,(%rsi)
	...
 68d:	00 00                	add    %al,(%rax)
 68f:	00 b0 1f 20 00 00    	add    %dh,0x201f(%rax)
 695:	00 00                	add    %al,(%rax)
 697:	00 07                	add    %al,(%rdi)
 699:	00 00                	add    %al,(%rax)
 69b:	00 09                	add    %cl,(%rcx)
	...
 6a5:	00 00                	add    %al,(%rax)
 6a7:	00 b8 1f 20 00 00    	add    %bh,0x201f(%rax)
 6ad:	00 00                	add    %al,(%rax)
 6af:	00 07                	add    %al,(%rdi)
 6b1:	00 00                	add    %al,(%rax)
 6b3:	00 0a                	add    %cl,(%rdx)
	...
 6bd:	00 00                	add    %al,(%rax)
 6bf:	00 c0                	add    %al,%al
 6c1:	1f                   	(bad)  
 6c2:	20 00                	and    %al,(%rax)
 6c4:	00 00                	add    %al,(%rax)
 6c6:	00 00                	add    %al,(%rax)
 6c8:	07                   	(bad)  
 6c9:	00 00                	add    %al,(%rax)
 6cb:	00 0b                	add    %cl,(%rbx)
	...
 6d5:	00 00                	add    %al,(%rax)
 6d7:	00 c8                	add    %cl,%al
 6d9:	1f                   	(bad)  
 6da:	20 00                	and    %al,(%rax)
 6dc:	00 00                	add    %al,(%rax)
 6de:	00 00                	add    %al,(%rax)
 6e0:	07                   	(bad)  
 6e1:	00 00                	add    %al,(%rax)
 6e3:	00 0c 00             	add    %cl,(%rax,%rax,1)
	...
 6ee:	00 00                	add    %al,(%rax)
 6f0:	d0 1f                	rcrb   (%rdi)
 6f2:	20 00                	and    %al,(%rax)
 6f4:	00 00                	add    %al,(%rax)
 6f6:	00 00                	add    %al,(%rax)
 6f8:	07                   	(bad)  
 6f9:	00 00                	add    %al,(%rax)
 6fb:	00 0d 00 00 00 00    	add    %cl,0x0(%rip)        # 701 <_init-0x7>
 701:	00 00                	add    %al,(%rax)
 703:	00 00                	add    %al,(%rax)
 705:	00 00                	add    %al,(%rax)
	...

Disassemblamento della sezione .init:

0000000000000708 <_init>:
 708:	48 83 ec 08          	sub    $0x8,%rsp
 70c:	48 8b 05 d5 18 20 00 	mov    0x2018d5(%rip),%rax        # 201fe8 <__gmon_start__>
 713:	48 85 c0             	test   %rax,%rax
 716:	74 02                	je     71a <_init+0x12>
 718:	ff d0                	callq  *%rax
 71a:	48 83 c4 08          	add    $0x8,%rsp
 71e:	c3                   	retq   

Disassemblamento della sezione .plt:

0000000000000720 <.plt>:
 720:	ff 35 52 18 20 00    	pushq  0x201852(%rip)        # 201f78 <_GLOBAL_OFFSET_TABLE_+0x8>
 726:	ff 25 54 18 20 00    	jmpq   *0x201854(%rip)        # 201f80 <_GLOBAL_OFFSET_TABLE_+0x10>
 72c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000000730 <puts@plt>:
 730:	ff 25 52 18 20 00    	jmpq   *0x201852(%rip)        # 201f88 <puts@GLIBC_2.2.5>
 736:	68 00 00 00 00       	pushq  $0x0
 73b:	e9 e0 ff ff ff       	jmpq   720 <.plt>

0000000000000740 <__stack_chk_fail@plt>:
 740:	ff 25 4a 18 20 00    	jmpq   *0x20184a(%rip)        # 201f90 <__stack_chk_fail@GLIBC_2.4>
 746:	68 01 00 00 00       	pushq  $0x1
 74b:	e9 d0 ff ff ff       	jmpq   720 <.plt>

0000000000000750 <printf@plt>:
 750:	ff 25 42 18 20 00    	jmpq   *0x201842(%rip)        # 201f98 <printf@GLIBC_2.2.5>
 756:	68 02 00 00 00       	pushq  $0x2
 75b:	e9 c0 ff ff ff       	jmpq   720 <.plt>

0000000000000760 <ioctl@plt>:
 760:	ff 25 3a 18 20 00    	jmpq   *0x20183a(%rip)        # 201fa0 <ioctl@GLIBC_2.2.5>
 766:	68 03 00 00 00       	pushq  $0x3
 76b:	e9 b0 ff ff ff       	jmpq   720 <.plt>

0000000000000770 <read@plt>:
 770:	ff 25 32 18 20 00    	jmpq   *0x201832(%rip)        # 201fa8 <read@GLIBC_2.2.5>
 776:	68 04 00 00 00       	pushq  $0x4
 77b:	e9 a0 ff ff ff       	jmpq   720 <.plt>

0000000000000780 <strtol@plt>:
 780:	ff 25 2a 18 20 00    	jmpq   *0x20182a(%rip)        # 201fb0 <strtol@GLIBC_2.2.5>
 786:	68 05 00 00 00       	pushq  $0x5
 78b:	e9 90 ff ff ff       	jmpq   720 <.plt>

0000000000000790 <malloc@plt>:
 790:	ff 25 22 18 20 00    	jmpq   *0x201822(%rip)        # 201fb8 <malloc@GLIBC_2.2.5>
 796:	68 06 00 00 00       	pushq  $0x6
 79b:	e9 80 ff ff ff       	jmpq   720 <.plt>

00000000000007a0 <open@plt>:
 7a0:	ff 25 1a 18 20 00    	jmpq   *0x20181a(%rip)        # 201fc0 <open@GLIBC_2.2.5>
 7a6:	68 07 00 00 00       	pushq  $0x7
 7ab:	e9 70 ff ff ff       	jmpq   720 <.plt>

00000000000007b0 <strtok@plt>:
 7b0:	ff 25 12 18 20 00    	jmpq   *0x201812(%rip)        # 201fc8 <strtok@GLIBC_2.2.5>
 7b6:	68 08 00 00 00       	pushq  $0x8
 7bb:	e9 60 ff ff ff       	jmpq   720 <.plt>

00000000000007c0 <exit@plt>:
 7c0:	ff 25 0a 18 20 00    	jmpq   *0x20180a(%rip)        # 201fd0 <exit@GLIBC_2.2.5>
 7c6:	68 09 00 00 00       	pushq  $0x9
 7cb:	e9 50 ff ff ff       	jmpq   720 <.plt>

Disassemblamento della sezione .plt.got:

00000000000007d0 <__cxa_finalize@plt>:
 7d0:	ff 25 22 18 20 00    	jmpq   *0x201822(%rip)        # 201ff8 <__cxa_finalize@GLIBC_2.2.5>
 7d6:	66 90                	xchg   %ax,%ax

Disassemblamento della sezione .text:

00000000000007e0 <_start>:
     7e0:	31 ed                	xor    %ebp,%ebp
     7e2:	49 89 d1             	mov    %rdx,%r9
     7e5:	5e                   	pop    %rsi
     7e6:	48 89 e2             	mov    %rsp,%rdx
     7e9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
     7ed:	50                   	push   %rax
     7ee:	54                   	push   %rsp
     7ef:	4c 8d 05 6a 0b 00 00 	lea    0xb6a(%rip),%r8        # 1360 <__libc_csu_fini>
     7f6:	48 8d 0d f3 0a 00 00 	lea    0xaf3(%rip),%rcx        # 12f0 <__libc_csu_init>
     7fd:	48 8d 3d bb 02 00 00 	lea    0x2bb(%rip),%rdi        # abf <main>
     804:	ff 15 d6 17 20 00    	callq  *0x2017d6(%rip)        # 201fe0 <__libc_start_main@GLIBC_2.2.5>
     80a:	f4                   	hlt    
     80b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000000810 <deregister_tm_clones>:
     810:	48 8d 3d f9 17 20 00 	lea    0x2017f9(%rip),%rdi        # 202010 <__TMC_END__>
     817:	55                   	push   %rbp
     818:	48 8d 05 f1 17 20 00 	lea    0x2017f1(%rip),%rax        # 202010 <__TMC_END__>
     81f:	48 39 f8             	cmp    %rdi,%rax
     822:	48 89 e5             	mov    %rsp,%rbp
     825:	74 19                	je     840 <deregister_tm_clones+0x30>
     827:	48 8b 05 aa 17 20 00 	mov    0x2017aa(%rip),%rax        # 201fd8 <_ITM_deregisterTMCloneTable>
     82e:	48 85 c0             	test   %rax,%rax
     831:	74 0d                	je     840 <deregister_tm_clones+0x30>
     833:	5d                   	pop    %rbp
     834:	ff e0                	jmpq   *%rax
     836:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
     83d:	00 00 00 
     840:	5d                   	pop    %rbp
     841:	c3                   	retq   
     842:	0f 1f 40 00          	nopl   0x0(%rax)
     846:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
     84d:	00 00 00 

0000000000000850 <register_tm_clones>:
     850:	48 8d 3d b9 17 20 00 	lea    0x2017b9(%rip),%rdi        # 202010 <__TMC_END__>
     857:	48 8d 35 b2 17 20 00 	lea    0x2017b2(%rip),%rsi        # 202010 <__TMC_END__>
     85e:	55                   	push   %rbp
     85f:	48 29 fe             	sub    %rdi,%rsi
     862:	48 89 e5             	mov    %rsp,%rbp
     865:	48 c1 fe 03          	sar    $0x3,%rsi
     869:	48 89 f0             	mov    %rsi,%rax
     86c:	48 c1 e8 3f          	shr    $0x3f,%rax
     870:	48 01 c6             	add    %rax,%rsi
     873:	48 d1 fe             	sar    %rsi
     876:	74 18                	je     890 <register_tm_clones+0x40>
     878:	48 8b 05 71 17 20 00 	mov    0x201771(%rip),%rax        # 201ff0 <_ITM_registerTMCloneTable>
     87f:	48 85 c0             	test   %rax,%rax
     882:	74 0c                	je     890 <register_tm_clones+0x40>
     884:	5d                   	pop    %rbp
     885:	ff e0                	jmpq   *%rax
     887:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
     88e:	00 00 
     890:	5d                   	pop    %rbp
     891:	c3                   	retq   
     892:	0f 1f 40 00          	nopl   0x0(%rax)
     896:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
     89d:	00 00 00 

00000000000008a0 <__do_global_dtors_aux>:
     8a0:	80 3d 79 17 20 00 00 	cmpb   $0x0,0x201779(%rip)        # 202020 <completed.7696>
     8a7:	75 2f                	jne    8d8 <__do_global_dtors_aux+0x38>
     8a9:	48 83 3d 47 17 20 00 	cmpq   $0x0,0x201747(%rip)        # 201ff8 <__cxa_finalize@GLIBC_2.2.5>
     8b0:	00 
     8b1:	55                   	push   %rbp
     8b2:	48 89 e5             	mov    %rsp,%rbp
     8b5:	74 0c                	je     8c3 <__do_global_dtors_aux+0x23>
     8b7:	48 8b 3d 4a 17 20 00 	mov    0x20174a(%rip),%rdi        # 202008 <__dso_handle>
     8be:	e8 0d ff ff ff       	callq  7d0 <__cxa_finalize@plt>
     8c3:	e8 48 ff ff ff       	callq  810 <deregister_tm_clones>
     8c8:	c6 05 51 17 20 00 01 	movb   $0x1,0x201751(%rip)        # 202020 <completed.7696>
     8cf:	5d                   	pop    %rbp
     8d0:	c3                   	retq   
     8d1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
     8d8:	f3 c3                	repz retq 
     8da:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000008e0 <frame_dummy>:
     8e0:	55                   	push   %rbp
     8e1:	48 89 e5             	mov    %rsp,%rbp
     8e4:	5d                   	pop    %rbp
     8e5:	e9 66 ff ff ff       	jmpq   850 <register_tm_clones>

00000000000008ea <function>:
     8ea:	55                   	push   %rbp
     8eb:	48 89 e5             	mov    %rsp,%rbp
     8ee:	48 83 ec 30          	sub    $0x30,%rsp
     8f2:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
     8f6:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
     8fd:	00 00 
     8ff:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
     903:	31 c0                	xor    %eax,%eax
     905:	48 8d 3d 7c 0a 00 00 	lea    0xa7c(%rip),%rdi        # 1388 <_IO_stdin_used+0x8>
     90c:	e8 1f fe ff ff       	callq  730 <puts@plt>
     911:	bf 08 00 00 00       	mov    $0x8,%edi
     916:	e8 eb 06 00 00       	callq  1006 <FlsAlloc>
     91b:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
     91f:	c6 45 e2 61          	movb   $0x61,-0x1e(%rbp)
     923:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
     927:	48 8d 45 e2          	lea    -0x1e(%rbp),%rax
     92b:	48 89 d6             	mov    %rdx,%rsi
     92e:	48 89 c7             	mov    %rax,%rdi
     931:	e8 34 08 00 00       	callq  116a <FlsSetValue>
     936:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
     93a:	48 8d 45 e3          	lea    -0x1d(%rbp),%rax
     93e:	48 89 d6             	mov    %rdx,%rsi
     941:	48 89 c7             	mov    %rax,%rdi
     944:	e8 df 08 00 00       	callq  1228 <FlsGetValue>
     949:	0f b6 45 e3          	movzbl -0x1d(%rbp),%eax
     94d:	0f be d0             	movsbl %al,%edx
     950:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
     954:	0f b6 00             	movzbl (%rax),%eax
     957:	0f be c0             	movsbl %al,%eax
     95a:	89 c6                	mov    %eax,%esi
     95c:	48 8d 3d 3d 0a 00 00 	lea    0xa3d(%rip),%rdi        # 13a0 <_IO_stdin_used+0x20>
     963:	b8 00 00 00 00       	mov    $0x0,%eax
     968:	e8 e3 fd ff ff       	callq  750 <printf@plt>
     96d:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
     971:	48 89 c7             	mov    %rax,%rdi
     974:	e8 3f 07 00 00       	callq  10b8 <FlsFree>
     979:	48 c7 45 e8 00 00 00 	movq   $0x0,-0x18(%rbp)
     980:	00 
     981:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
     985:	48 ba bd 42 7a e5 d5 	movabs $0xd6bf94d5e57a42bd,%rdx
     98c:	94 bf d6 
     98f:	48 89 c8             	mov    %rcx,%rax
     992:	48 f7 ea             	imul   %rdx
     995:	48 8d 04 0a          	lea    (%rdx,%rcx,1),%rax
     999:	48 c1 f8 17          	sar    $0x17,%rax
     99d:	48 89 c2             	mov    %rax,%rdx
     9a0:	48 89 c8             	mov    %rcx,%rax
     9a3:	48 c1 f8 3f          	sar    $0x3f,%rax
     9a7:	48 29 c2             	sub    %rax,%rdx
     9aa:	48 89 d0             	mov    %rdx,%rax
     9ad:	48 69 c0 80 96 98 00 	imul   $0x989680,%rax,%rax
     9b4:	48 29 c1             	sub    %rax,%rcx
     9b7:	48 89 c8             	mov    %rcx,%rax
     9ba:	48 85 c0             	test   %rax,%rax
     9bd:	75 2a                	jne    9e9 <function+0xff>
     9bf:	48 8d 3d fc 09 00 00 	lea    0x9fc(%rip),%rdi        # 13c2 <_IO_stdin_used+0x42>
     9c6:	e8 65 fd ff ff       	callq  730 <puts@plt>
     9cb:	90                   	nop
     9cc:	bf 01 00 00 00       	mov    $0x1,%edi
     9d1:	e8 81 05 00 00       	callq  f57 <SwitchToFiber>
     9d6:	48 c7 45 e8 00 00 00 	movq   $0x0,-0x18(%rbp)
     9dd:	00 
     9de:	66 0f ef c0          	pxor   %xmm0,%xmm0
     9e2:	f3 0f 11 45 e4       	movss  %xmm0,-0x1c(%rbp)
     9e7:	eb 07                	jmp    9f0 <function+0x106>
     9e9:	48 83 45 e8 01       	addq   $0x1,-0x18(%rbp)
     9ee:	eb 91                	jmp    981 <function+0x97>
     9f0:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
     9f4:	48 ba bd 42 7a e5 d5 	movabs $0xd6bf94d5e57a42bd,%rdx
     9fb:	94 bf d6 
     9fe:	48 89 c8             	mov    %rcx,%rax
     a01:	48 f7 ea             	imul   %rdx
     a04:	48 8d 04 0a          	lea    (%rdx,%rcx,1),%rax
     a08:	48 c1 f8 17          	sar    $0x17,%rax
     a0c:	48 89 c2             	mov    %rax,%rdx
     a0f:	48 89 c8             	mov    %rcx,%rax
     a12:	48 c1 f8 3f          	sar    $0x3f,%rax
     a16:	48 29 c2             	sub    %rax,%rdx
     a19:	48 89 d0             	mov    %rdx,%rax
     a1c:	48 69 c0 80 96 98 00 	imul   $0x989680,%rax,%rax
     a23:	48 29 c1             	sub    %rax,%rcx
     a26:	48 89 c8             	mov    %rcx,%rax
     a29:	48 85 c0             	test   %rax,%rax
     a2c:	75 2c                	jne    a5a <function+0x170>
     a2e:	f3 0f 5a 45 e4       	cvtss2sd -0x1c(%rbp),%xmm0
     a33:	48 8d 3d 8d 09 00 00 	lea    0x98d(%rip),%rdi        # 13c7 <_IO_stdin_used+0x47>
     a3a:	b8 01 00 00 00       	mov    $0x1,%eax
     a3f:	e8 0c fd ff ff       	callq  750 <printf@plt>
     a44:	f3 0f 10 4d e4       	movss  -0x1c(%rbp),%xmm1
     a49:	f3 0f 10 05 af 09 00 	movss  0x9af(%rip),%xmm0        # 1400 <_IO_stdin_used+0x80>
     a50:	00 
     a51:	f3 0f 58 c1          	addss  %xmm1,%xmm0
     a55:	f3 0f 11 45 e4       	movss  %xmm0,-0x1c(%rbp)
     a5a:	f3 0f 10 45 e4       	movss  -0x1c(%rbp),%xmm0
     a5f:	f3 0f 10 0d 9d 09 00 	movss  0x99d(%rip),%xmm1        # 1404 <_IO_stdin_used+0x84>
     a66:	00 
     a67:	0f 2e c1             	ucomiss %xmm1,%xmm0
     a6a:	77 0a                	ja     a76 <function+0x18c>
     a6c:	48 83 45 e8 01       	addq   $0x1,-0x18(%rbp)
     a71:	e9 7a ff ff ff       	jmpq   9f0 <function+0x106>
     a76:	90                   	nop
     a77:	bf 01 00 00 00       	mov    $0x1,%edi
     a7c:	e8 d6 04 00 00       	callq  f57 <SwitchToFiber>
     a81:	f3 0f 5a 45 e4       	cvtss2sd -0x1c(%rbp),%xmm0
     a86:	f2 0f 10 0d 7a 09 00 	movsd  0x97a(%rip),%xmm1        # 1408 <_IO_stdin_used+0x88>
     a8d:	00 
     a8e:	f2 0f 58 c1          	addsd  %xmm1,%xmm0
     a92:	f2 0f 5a d0          	cvtsd2ss %xmm0,%xmm2
     a96:	f3 0f 11 55 e4       	movss  %xmm2,-0x1c(%rbp)
     a9b:	f3 0f 10 45 e4       	movss  -0x1c(%rbp),%xmm0
     aa0:	0f 2e 05 69 09 00 00 	ucomiss 0x969(%rip),%xmm0        # 1410 <_IO_stdin_used+0x90>
     aa7:	76 0c                	jbe    ab5 <function+0x1cb>
     aa9:	48 8d 3d 21 09 00 00 	lea    0x921(%rip),%rdi        # 13d1 <_IO_stdin_used+0x51>
     ab0:	e8 7b fc ff ff       	callq  730 <puts@plt>
     ab5:	bf 00 00 00 00       	mov    $0x0,%edi
     aba:	e8 01 fd ff ff       	callq  7c0 <exit@plt>

0000000000000abf <main>:
     abf:	55                   	push   %rbp
     ac0:	48 89 e5             	mov    %rsp,%rbp
     ac3:	48 83 ec 40          	sub    $0x40,%rsp
     ac7:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
     ace:	00 00 
     ad0:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
     ad4:	31 c0                	xor    %eax,%eax
     ad6:	48 8d 3d 04 09 00 00 	lea    0x904(%rip),%rdi        # 13e1 <_IO_stdin_used+0x61>
     add:	e8 4e fc ff ff       	callq  730 <puts@plt>
     ae2:	b8 00 00 00 00       	mov    $0x0,%eax
     ae7:	e8 1f 03 00 00       	callq  e0b <ConvertThreadToFiber>
     aec:	89 45 e0             	mov    %eax,-0x20(%rbp)
     aef:	c6 45 df 63          	movb   $0x63,-0x21(%rbp)
     af3:	48 8d 45 df          	lea    -0x21(%rbp),%rax
     af7:	48 89 c2             	mov    %rax,%rdx
     afa:	be 06 00 00 00       	mov    $0x6,%esi
     aff:	48 8d 3d e4 fd ff ff 	lea    -0x21c(%rip),%rdi        # 8ea <function>
     b06:	e8 3e 03 00 00       	callq  e49 <CreateFiber>
     b0b:	89 45 e4             	mov    %eax,-0x1c(%rbp)
     b0e:	8b 45 e4             	mov    -0x1c(%rbp),%eax
     b11:	89 c7                	mov    %eax,%edi
     b13:	e8 3f 04 00 00       	callq  f57 <SwitchToFiber>
     b18:	48 c7 45 e8 00 00 00 	movq   $0x0,-0x18(%rbp)
     b1f:	00 
     b20:	66 0f ef c0          	pxor   %xmm0,%xmm0
     b24:	f2 0f 11 45 f0       	movsd  %xmm0,-0x10(%rbp)
     b29:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
     b2d:	48 ba bd 42 7a e5 d5 	movabs $0xd6bf94d5e57a42bd,%rdx
     b34:	94 bf d6 
     b37:	48 89 c8             	mov    %rcx,%rax
     b3a:	48 f7 ea             	imul   %rdx
     b3d:	48 8d 04 0a          	lea    (%rdx,%rcx,1),%rax
     b41:	48 c1 f8 17          	sar    $0x17,%rax
     b45:	48 89 c2             	mov    %rax,%rdx
     b48:	48 89 c8             	mov    %rcx,%rax
     b4b:	48 c1 f8 3f          	sar    $0x3f,%rax
     b4f:	48 29 c2             	sub    %rax,%rdx
     b52:	48 89 d0             	mov    %rdx,%rax
     b55:	48 69 c0 80 96 98 00 	imul   $0x989680,%rax,%rax
     b5c:	48 29 c1             	sub    %rax,%rcx
     b5f:	48 89 c8             	mov    %rcx,%rax
     b62:	48 85 c0             	test   %rax,%rax
     b65:	75 41                	jne    ba8 <main+0xe9>
     b67:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
     b6b:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
     b6f:	f2 0f 10 45 c8       	movsd  -0x38(%rbp),%xmm0
     b74:	48 8d 3d 77 08 00 00 	lea    0x877(%rip),%rdi        # 13f2 <_IO_stdin_used+0x72>
     b7b:	b8 01 00 00 00       	mov    $0x1,%eax
     b80:	e8 cb fb ff ff       	callq  750 <printf@plt>
     b85:	f2 0f 10 4d f0       	movsd  -0x10(%rbp),%xmm1
     b8a:	f2 0f 10 05 86 08 00 	movsd  0x886(%rip),%xmm0        # 1418 <_IO_stdin_used+0x98>
     b91:	00 
     b92:	f2 0f 58 c1          	addsd  %xmm1,%xmm0
     b96:	f2 0f 11 45 f0       	movsd  %xmm0,-0x10(%rbp)
     b9b:	90                   	nop
     b9c:	8b 45 e4             	mov    -0x1c(%rbp),%eax
     b9f:	89 c7                	mov    %eax,%edi
     ba1:	e8 b1 03 00 00       	callq  f57 <SwitchToFiber>
     ba6:	eb 0a                	jmp    bb2 <main+0xf3>
     ba8:	48 83 45 e8 01       	addq   $0x1,-0x18(%rbp)
     bad:	e9 77 ff ff ff       	jmpq   b29 <main+0x6a>
     bb2:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
     bb6:	48 ba bd 42 7a e5 d5 	movabs $0xd6bf94d5e57a42bd,%rdx
     bbd:	94 bf d6 
     bc0:	48 89 c8             	mov    %rcx,%rax
     bc3:	48 f7 ea             	imul   %rdx
     bc6:	48 8d 04 0a          	lea    (%rdx,%rcx,1),%rax
     bca:	48 c1 f8 17          	sar    $0x17,%rax
     bce:	48 89 c2             	mov    %rax,%rdx
     bd1:	48 89 c8             	mov    %rcx,%rax
     bd4:	48 c1 f8 3f          	sar    $0x3f,%rax
     bd8:	48 29 c2             	sub    %rax,%rdx
     bdb:	48 89 d0             	mov    %rdx,%rax
     bde:	48 69 c0 80 96 98 00 	imul   $0x989680,%rax,%rax
     be5:	48 29 c1             	sub    %rax,%rcx
     be8:	48 89 c8             	mov    %rcx,%rax
     beb:	48 85 c0             	test   %rax,%rax
     bee:	75 49                	jne    c39 <main+0x17a>
     bf0:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
     bf4:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
     bf8:	f2 0f 10 45 c8       	movsd  -0x38(%rbp),%xmm0
     bfd:	48 8d 3d ee 07 00 00 	lea    0x7ee(%rip),%rdi        # 13f2 <_IO_stdin_used+0x72>
     c04:	b8 01 00 00 00       	mov    $0x1,%eax
     c09:	e8 42 fb ff ff       	callq  750 <printf@plt>
     c0e:	f2 0f 10 4d f0       	movsd  -0x10(%rbp),%xmm1
     c13:	f2 0f 10 05 fd 07 00 	movsd  0x7fd(%rip),%xmm0        # 1418 <_IO_stdin_used+0x98>
     c1a:	00 
     c1b:	f2 0f 58 c1          	addsd  %xmm1,%xmm0
     c1f:	f2 0f 11 45 f0       	movsd  %xmm0,-0x10(%rbp)
     c24:	90                   	nop
     c25:	8b 45 e4             	mov    -0x1c(%rbp),%eax
     c28:	89 c7                	mov    %eax,%edi
     c2a:	e8 28 03 00 00       	callq  f57 <SwitchToFiber>
     c2f:	bf 00 00 00 00       	mov    $0x0,%edi
     c34:	e8 87 fb ff ff       	callq  7c0 <exit@plt>
     c39:	48 83 45 e8 01       	addq   $0x1,-0x18(%rbp)
     c3e:	e9 6f ff ff ff       	jmpq   bb2 <main+0xf3>

0000000000000c43 <log2_64>:
     c43:	55                   	push   %rbp
     c44:	48 89 e5             	mov    %rsp,%rbp
     c47:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
     c4b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     c4f:	48 d1 e8             	shr    %rax
     c52:	48 09 45 f8          	or     %rax,-0x8(%rbp)
     c56:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     c5a:	48 c1 e8 02          	shr    $0x2,%rax
     c5e:	48 09 45 f8          	or     %rax,-0x8(%rbp)
     c62:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     c66:	48 c1 e8 04          	shr    $0x4,%rax
     c6a:	48 09 45 f8          	or     %rax,-0x8(%rbp)
     c6e:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     c72:	48 c1 e8 08          	shr    $0x8,%rax
     c76:	48 09 45 f8          	or     %rax,-0x8(%rbp)
     c7a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     c7e:	48 c1 e8 10          	shr    $0x10,%rax
     c82:	48 09 45 f8          	or     %rax,-0x8(%rbp)
     c86:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     c8a:	48 c1 e8 20          	shr    $0x20,%rax
     c8e:	48 09 45 f8          	or     %rax,-0x8(%rbp)
     c92:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     c96:	48 d1 e8             	shr    %rax
     c99:	48 89 c2             	mov    %rax,%rdx
     c9c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     ca0:	48 29 d0             	sub    %rdx,%rax
     ca3:	48 89 c2             	mov    %rax,%rdx
     ca6:	48 b8 c2 28 4e 9a e5 	movabs $0x7edd5e59a4e28c2,%rax
     cad:	d5 ed 07 
     cb0:	48 0f af c2          	imul   %rdx,%rax
     cb4:	48 c1 e8 3a          	shr    $0x3a,%rax
     cb8:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
     cbf:	00 
     cc0:	48 8d 05 59 07 00 00 	lea    0x759(%rip),%rax        # 1420 <tab64>
     cc7:	8b 04 02             	mov    (%rdx,%rax,1),%eax
     cca:	5d                   	pop    %rbp
     ccb:	c3                   	retq   

0000000000000ccc <fiberlib_init>:
     ccc:	55                   	push   %rbp
     ccd:	48 89 e5             	mov    %rsp,%rbp
     cd0:	48 81 ec 40 01 00 00 	sub    $0x140,%rsp
     cd7:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
     cde:	00 00 
     ce0:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
     ce4:	31 c0                	xor    %eax,%eax
     ce6:	be 00 00 00 00       	mov    $0x0,%esi
     ceb:	48 8d 3d 2e 08 00 00 	lea    0x82e(%rip),%rdi        # 1520 <tab64+0x100>
     cf2:	b8 00 00 00 00       	mov    $0x0,%eax
     cf7:	e8 a4 fa ff ff       	callq  7a0 <open@plt>
     cfc:	89 05 96 13 20 00    	mov    %eax,0x201396(%rip)        # 202098 <fd>
     d02:	8b 05 90 13 20 00    	mov    0x201390(%rip),%eax        # 202098 <fd>
     d08:	48 8d 8d f0 fe ff ff 	lea    -0x110(%rbp),%rcx
     d0f:	ba 00 01 00 00       	mov    $0x100,%edx
     d14:	48 89 ce             	mov    %rcx,%rsi
     d17:	89 c7                	mov    %eax,%edi
     d19:	e8 52 fa ff ff       	callq  770 <read@plt>
     d1e:	48 89 85 d8 fe ff ff 	mov    %rax,-0x128(%rbp)
     d25:	66 c7 85 ee fe ff ff 	movw   $0xa,-0x112(%rbp)
     d2c:	0a 00 
     d2e:	48 8d 95 ee fe ff ff 	lea    -0x112(%rbp),%rdx
     d35:	48 8d 85 f0 fe ff ff 	lea    -0x110(%rbp),%rax
     d3c:	48 89 d6             	mov    %rdx,%rsi
     d3f:	48 89 c7             	mov    %rax,%rdi
     d42:	e8 69 fa ff ff       	callq  7b0 <strtok@plt>
     d47:	48 89 85 d0 fe ff ff 	mov    %rax,-0x130(%rbp)
     d4e:	c7 85 c4 fe ff ff 00 	movl   $0x0,-0x13c(%rbp)
     d55:	00 00 00 
     d58:	eb 5e                	jmp    db8 <fiberlib_init+0xec>
     d5a:	48 8d 8d c8 fe ff ff 	lea    -0x138(%rbp),%rcx
     d61:	48 8b 85 d0 fe ff ff 	mov    -0x130(%rbp),%rax
     d68:	ba 0a 00 00 00       	mov    $0xa,%edx
     d6d:	48 89 ce             	mov    %rcx,%rsi
     d70:	48 89 c7             	mov    %rax,%rdi
     d73:	e8 08 fa ff ff       	callq  780 <strtol@plt>
     d78:	48 89 c1             	mov    %rax,%rcx
     d7b:	8b 85 c4 fe ff ff    	mov    -0x13c(%rbp),%eax
     d81:	48 98                	cltq   
     d83:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
     d8a:	00 
     d8b:	48 8d 05 ce 12 20 00 	lea    0x2012ce(%rip),%rax        # 202060 <ioctl_numbers>
     d92:	48 89 0c 02          	mov    %rcx,(%rdx,%rax,1)
     d96:	48 8d 85 ee fe ff ff 	lea    -0x112(%rbp),%rax
     d9d:	48 89 c6             	mov    %rax,%rsi
     da0:	bf 00 00 00 00       	mov    $0x0,%edi
     da5:	e8 06 fa ff ff       	callq  7b0 <strtok@plt>
     daa:	48 89 85 d0 fe ff ff 	mov    %rax,-0x130(%rbp)
     db1:	83 85 c4 fe ff ff 01 	addl   $0x1,-0x13c(%rbp)
     db8:	48 83 bd d0 fe ff ff 	cmpq   $0x0,-0x130(%rbp)
     dbf:	00 
     dc0:	75 98                	jne    d5a <fiberlib_init+0x8e>
     dc2:	c7 05 74 12 20 00 01 	movl   $0x1,0x201274(%rip)        # 202040 <fiberlib_initialized>
     dc9:	00 00 00 
     dcc:	66 0f ef c0          	pxor   %xmm0,%xmm0
     dd0:	f2 0f 11 85 e0 fe ff 	movsd  %xmm0,-0x120(%rbp)
     dd7:	ff 
     dd8:	f2 0f 10 8d e0 fe ff 	movsd  -0x120(%rbp),%xmm1
     ddf:	ff 
     de0:	f2 0f 10 05 48 07 00 	movsd  0x748(%rip),%xmm0        # 1530 <tab64+0x110>
     de7:	00 
     de8:	f2 0f 58 c1          	addsd  %xmm1,%xmm0
     dec:	f2 0f 11 85 e0 fe ff 	movsd  %xmm0,-0x120(%rbp)
     df3:	ff 
     df4:	90                   	nop
     df5:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
     df9:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
     e00:	00 00 
     e02:	74 05                	je     e09 <fiberlib_init+0x13d>
     e04:	e8 37 f9 ff ff       	callq  740 <__stack_chk_fail@plt>
     e09:	c9                   	leaveq 
     e0a:	c3                   	retq   

0000000000000e0b <ConvertThreadToFiber>:
     e0b:	55                   	push   %rbp
     e0c:	48 89 e5             	mov    %rsp,%rbp
     e0f:	8b 05 2b 12 20 00    	mov    0x20122b(%rip),%eax        # 202040 <fiberlib_initialized>
     e15:	85 c0                	test   %eax,%eax
     e17:	75 0a                	jne    e23 <ConvertThreadToFiber+0x18>
     e19:	b8 00 00 00 00       	mov    $0x0,%eax
     e1e:	e8 a9 fe ff ff       	callq  ccc <fiberlib_init>
     e23:	48 8b 05 36 12 20 00 	mov    0x201236(%rip),%rax        # 202060 <ioctl_numbers>
     e2a:	48 89 c1             	mov    %rax,%rcx
     e2d:	8b 05 65 12 20 00    	mov    0x201265(%rip),%eax        # 202098 <fd>
     e33:	ba 00 00 00 00       	mov    $0x0,%edx
     e38:	48 89 ce             	mov    %rcx,%rsi
     e3b:	89 c7                	mov    %eax,%edi
     e3d:	b8 00 00 00 00       	mov    $0x0,%eax
     e42:	e8 19 f9 ff ff       	callq  760 <ioctl@plt>
     e47:	5d                   	pop    %rbp
     e48:	c3                   	retq   

0000000000000e49 <CreateFiber>:
     e49:	55                   	push   %rbp
     e4a:	48 89 e5             	mov    %rsp,%rbp
     e4d:	48 83 c4 80          	add    $0xffffffffffffff80,%rsp
     e51:	48 89 7d 98          	mov    %rdi,-0x68(%rbp)
     e55:	48 89 75 90          	mov    %rsi,-0x70(%rbp)
     e59:	48 89 55 88          	mov    %rdx,-0x78(%rbp)
     e5d:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
     e64:	00 00 
     e66:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
     e6a:	31 c0                	xor    %eax,%eax
     e6c:	8b 05 ce 11 20 00    	mov    0x2011ce(%rip),%eax        # 202040 <fiberlib_initialized>
     e72:	85 c0                	test   %eax,%eax
     e74:	75 0a                	jne    e80 <CreateFiber+0x37>
     e76:	b8 00 00 00 00       	mov    $0x0,%eax
     e7b:	e8 4c fe ff ff       	callq  ccc <fiberlib_init>
     e80:	48 8b 45 90          	mov    -0x70(%rbp),%rax
     e84:	48 89 c7             	mov    %rax,%rdi
     e87:	e8 b7 fd ff ff       	callq  c43 <log2_64>
     e8c:	89 45 ac             	mov    %eax,-0x54(%rbp)
     e8f:	8b 45 ac             	mov    -0x54(%rbp),%eax
     e92:	ba 02 00 00 00       	mov    $0x2,%edx
     e97:	89 c1                	mov    %eax,%ecx
     e99:	d3 e2                	shl    %cl,%edx
     e9b:	89 d0                	mov    %edx,%eax
     e9d:	48 98                	cltq   
     e9f:	48 39 45 90          	cmp    %rax,-0x70(%rbp)
     ea3:	74 04                	je     ea9 <CreateFiber+0x60>
     ea5:	83 45 ac 01          	addl   $0x1,-0x54(%rbp)
     ea9:	48 c7 45 b0 00 00 00 	movq   $0x0,-0x50(%rbp)
     eb0:	00 
     eb1:	48 c7 45 b8 00 00 00 	movq   $0x0,-0x48(%rbp)
     eb8:	00 
     eb9:	48 c7 45 c0 00 00 00 	movq   $0x0,-0x40(%rbp)
     ec0:	00 
     ec1:	48 c7 45 c8 00 00 00 	movq   $0x0,-0x38(%rbp)
     ec8:	00 
     ec9:	48 c7 45 d0 00 00 00 	movq   $0x0,-0x30(%rbp)
     ed0:	00 
     ed1:	48 c7 45 d8 00 00 00 	movq   $0x0,-0x28(%rbp)
     ed8:	00 
     ed9:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
     ee0:	00 
     ee1:	48 c7 45 e8 00 00 00 	movq   $0x0,-0x18(%rbp)
     ee8:	00 
     ee9:	8b 45 ac             	mov    -0x54(%rbp),%eax
     eec:	48 98                	cltq   
     eee:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
     ef2:	48 8b 45 98          	mov    -0x68(%rbp),%rax
     ef6:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
     efa:	48 8b 45 88          	mov    -0x78(%rbp),%rax
     efe:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
     f02:	8b 45 ac             	mov    -0x54(%rbp),%eax
     f05:	ba 00 10 00 00       	mov    $0x1000,%edx
     f0a:	89 c1                	mov    %eax,%ecx
     f0c:	d3 e2                	shl    %cl,%edx
     f0e:	89 d0                	mov    %edx,%eax
     f10:	48 98                	cltq   
     f12:	48 89 c7             	mov    %rax,%rdi
     f15:	e8 76 f8 ff ff       	callq  790 <malloc@plt>
     f1a:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
     f1e:	48 8b 05 43 11 20 00 	mov    0x201143(%rip),%rax        # 202068 <ioctl_numbers+0x8>
     f25:	48 89 c1             	mov    %rax,%rcx
     f28:	8b 05 6a 11 20 00    	mov    0x20116a(%rip),%eax        # 202098 <fd>
     f2e:	48 8d 55 b0          	lea    -0x50(%rbp),%rdx
     f32:	48 89 ce             	mov    %rcx,%rsi
     f35:	89 c7                	mov    %eax,%edi
     f37:	b8 00 00 00 00       	mov    $0x0,%eax
     f3c:	e8 1f f8 ff ff       	callq  760 <ioctl@plt>
     f41:	48 8b 75 f8          	mov    -0x8(%rbp),%rsi
     f45:	64 48 33 34 25 28 00 	xor    %fs:0x28,%rsi
     f4c:	00 00 
     f4e:	74 05                	je     f55 <CreateFiber+0x10c>
     f50:	e8 eb f7 ff ff       	callq  740 <__stack_chk_fail@plt>
     f55:	c9                   	leaveq 
     f56:	c3                   	retq   

0000000000000f57 <SwitchToFiber>:
     f57:	55                   	push   %rbp
     f58:	48 89 e5             	mov    %rsp,%rbp
     f5b:	48 83 ec 60          	sub    $0x60,%rsp
     f5f:	89 7d ac             	mov    %edi,-0x54(%rbp)
     f62:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
     f69:	00 00 
     f6b:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
     f6f:	31 c0                	xor    %eax,%eax
     f71:	8b 05 c9 10 20 00    	mov    0x2010c9(%rip),%eax        # 202040 <fiberlib_initialized>
     f77:	85 c0                	test   %eax,%eax
     f79:	75 0a                	jne    f85 <SwitchToFiber+0x2e>
     f7b:	b8 00 00 00 00       	mov    $0x0,%eax
     f80:	e8 47 fd ff ff       	callq  ccc <fiberlib_init>
     f85:	48 c7 45 b0 00 00 00 	movq   $0x0,-0x50(%rbp)
     f8c:	00 
     f8d:	48 c7 45 b8 00 00 00 	movq   $0x0,-0x48(%rbp)
     f94:	00 
     f95:	48 c7 45 c0 00 00 00 	movq   $0x0,-0x40(%rbp)
     f9c:	00 
     f9d:	48 c7 45 c8 00 00 00 	movq   $0x0,-0x38(%rbp)
     fa4:	00 
     fa5:	48 c7 45 d0 00 00 00 	movq   $0x0,-0x30(%rbp)
     fac:	00 
     fad:	48 c7 45 d8 00 00 00 	movq   $0x0,-0x28(%rbp)
     fb4:	00 
     fb5:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
     fbc:	00 
     fbd:	48 c7 45 e8 00 00 00 	movq   $0x0,-0x18(%rbp)
     fc4:	00 
     fc5:	8b 45 ac             	mov    -0x54(%rbp),%eax
     fc8:	89 45 d0             	mov    %eax,-0x30(%rbp)
     fcb:	48 8b 05 9e 10 20 00 	mov    0x20109e(%rip),%rax        # 202070 <ioctl_numbers+0x10>
     fd2:	48 89 c1             	mov    %rax,%rcx
     fd5:	8b 05 bd 10 20 00    	mov    0x2010bd(%rip),%eax        # 202098 <fd>
     fdb:	48 8d 55 b0          	lea    -0x50(%rbp),%rdx
     fdf:	48 89 ce             	mov    %rcx,%rsi
     fe2:	89 c7                	mov    %eax,%edi
     fe4:	b8 00 00 00 00       	mov    $0x0,%eax
     fe9:	e8 72 f7 ff ff       	callq  760 <ioctl@plt>
     fee:	48 98                	cltq   
     ff0:	48 8b 75 f8          	mov    -0x8(%rbp),%rsi
     ff4:	64 48 33 34 25 28 00 	xor    %fs:0x28,%rsi
     ffb:	00 00 
     ffd:	74 05                	je     1004 <SwitchToFiber+0xad>
     fff:	e8 3c f7 ff ff       	callq  740 <__stack_chk_fail@plt>
    1004:	c9                   	leaveq 
    1005:	c3                   	retq   

0000000000001006 <FlsAlloc>:
    1006:	55                   	push   %rbp
    1007:	48 89 e5             	mov    %rsp,%rbp
    100a:	48 83 ec 60          	sub    $0x60,%rsp
    100e:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
    1012:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1019:	00 00 
    101b:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    101f:	31 c0                	xor    %eax,%eax
    1021:	8b 05 19 10 20 00    	mov    0x201019(%rip),%eax        # 202040 <fiberlib_initialized>
    1027:	85 c0                	test   %eax,%eax
    1029:	75 0a                	jne    1035 <FlsAlloc+0x2f>
    102b:	b8 00 00 00 00       	mov    $0x0,%eax
    1030:	e8 97 fc ff ff       	callq  ccc <fiberlib_init>
    1035:	48 c7 45 b0 00 00 00 	movq   $0x0,-0x50(%rbp)
    103c:	00 
    103d:	48 c7 45 b8 00 00 00 	movq   $0x0,-0x48(%rbp)
    1044:	00 
    1045:	48 c7 45 c0 00 00 00 	movq   $0x0,-0x40(%rbp)
    104c:	00 
    104d:	48 c7 45 c8 00 00 00 	movq   $0x0,-0x38(%rbp)
    1054:	00 
    1055:	48 c7 45 d0 00 00 00 	movq   $0x0,-0x30(%rbp)
    105c:	00 
    105d:	48 c7 45 d8 00 00 00 	movq   $0x0,-0x28(%rbp)
    1064:	00 
    1065:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
    106c:	00 
    106d:	48 c7 45 e8 00 00 00 	movq   $0x0,-0x18(%rbp)
    1074:	00 
    1075:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    1079:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    107d:	48 8b 05 f4 0f 20 00 	mov    0x200ff4(%rip),%rax        # 202078 <ioctl_numbers+0x18>
    1084:	48 89 c1             	mov    %rax,%rcx
    1087:	8b 05 0b 10 20 00    	mov    0x20100b(%rip),%eax        # 202098 <fd>
    108d:	48 8d 55 b0          	lea    -0x50(%rbp),%rdx
    1091:	48 89 ce             	mov    %rcx,%rsi
    1094:	89 c7                	mov    %eax,%edi
    1096:	b8 00 00 00 00       	mov    $0x0,%eax
    109b:	e8 c0 f6 ff ff       	callq  760 <ioctl@plt>
    10a0:	48 98                	cltq   
    10a2:	48 8b 75 f8          	mov    -0x8(%rbp),%rsi
    10a6:	64 48 33 34 25 28 00 	xor    %fs:0x28,%rsi
    10ad:	00 00 
    10af:	74 05                	je     10b6 <FlsAlloc+0xb0>
    10b1:	e8 8a f6 ff ff       	callq  740 <__stack_chk_fail@plt>
    10b6:	c9                   	leaveq 
    10b7:	c3                   	retq   

00000000000010b8 <FlsFree>:
    10b8:	55                   	push   %rbp
    10b9:	48 89 e5             	mov    %rsp,%rbp
    10bc:	48 83 ec 60          	sub    $0x60,%rsp
    10c0:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
    10c4:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    10cb:	00 00 
    10cd:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    10d1:	31 c0                	xor    %eax,%eax
    10d3:	8b 05 67 0f 20 00    	mov    0x200f67(%rip),%eax        # 202040 <fiberlib_initialized>
    10d9:	85 c0                	test   %eax,%eax
    10db:	75 0a                	jne    10e7 <FlsFree+0x2f>
    10dd:	b8 00 00 00 00       	mov    $0x0,%eax
    10e2:	e8 e5 fb ff ff       	callq  ccc <fiberlib_init>
    10e7:	48 c7 45 b0 00 00 00 	movq   $0x0,-0x50(%rbp)
    10ee:	00 
    10ef:	48 c7 45 b8 00 00 00 	movq   $0x0,-0x48(%rbp)
    10f6:	00 
    10f7:	48 c7 45 c0 00 00 00 	movq   $0x0,-0x40(%rbp)
    10fe:	00 
    10ff:	48 c7 45 c8 00 00 00 	movq   $0x0,-0x38(%rbp)
    1106:	00 
    1107:	48 c7 45 d0 00 00 00 	movq   $0x0,-0x30(%rbp)
    110e:	00 
    110f:	48 c7 45 d8 00 00 00 	movq   $0x0,-0x28(%rbp)
    1116:	00 
    1117:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
    111e:	00 
    111f:	48 c7 45 e8 00 00 00 	movq   $0x0,-0x18(%rbp)
    1126:	00 
    1127:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    112b:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    112f:	48 8b 05 42 0f 20 00 	mov    0x200f42(%rip),%rax        # 202078 <ioctl_numbers+0x18>
    1136:	48 89 c1             	mov    %rax,%rcx
    1139:	8b 05 59 0f 20 00    	mov    0x200f59(%rip),%eax        # 202098 <fd>
    113f:	48 8d 55 b0          	lea    -0x50(%rbp),%rdx
    1143:	48 89 ce             	mov    %rcx,%rsi
    1146:	89 c7                	mov    %eax,%edi
    1148:	b8 00 00 00 00       	mov    $0x0,%eax
    114d:	e8 0e f6 ff ff       	callq  760 <ioctl@plt>
    1152:	48 98                	cltq   
    1154:	48 8b 75 f8          	mov    -0x8(%rbp),%rsi
    1158:	64 48 33 34 25 28 00 	xor    %fs:0x28,%rsi
    115f:	00 00 
    1161:	74 05                	je     1168 <FlsFree+0xb0>
    1163:	e8 d8 f5 ff ff       	callq  740 <__stack_chk_fail@plt>
    1168:	c9                   	leaveq 
    1169:	c3                   	retq   

000000000000116a <FlsSetValue>:
    116a:	55                   	push   %rbp
    116b:	48 89 e5             	mov    %rsp,%rbp
    116e:	48 83 ec 60          	sub    $0x60,%rsp
    1172:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
    1176:	48 89 75 a0          	mov    %rsi,-0x60(%rbp)
    117a:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1181:	00 00 
    1183:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1187:	31 c0                	xor    %eax,%eax
    1189:	8b 05 b1 0e 20 00    	mov    0x200eb1(%rip),%eax        # 202040 <fiberlib_initialized>
    118f:	85 c0                	test   %eax,%eax
    1191:	75 0a                	jne    119d <FlsSetValue+0x33>
    1193:	b8 00 00 00 00       	mov    $0x0,%eax
    1198:	e8 2f fb ff ff       	callq  ccc <fiberlib_init>
    119d:	48 c7 45 b0 00 00 00 	movq   $0x0,-0x50(%rbp)
    11a4:	00 
    11a5:	48 c7 45 b8 00 00 00 	movq   $0x0,-0x48(%rbp)
    11ac:	00 
    11ad:	48 c7 45 c0 00 00 00 	movq   $0x0,-0x40(%rbp)
    11b4:	00 
    11b5:	48 c7 45 c8 00 00 00 	movq   $0x0,-0x38(%rbp)
    11bc:	00 
    11bd:	48 c7 45 d0 00 00 00 	movq   $0x0,-0x30(%rbp)
    11c4:	00 
    11c5:	48 c7 45 d8 00 00 00 	movq   $0x0,-0x28(%rbp)
    11cc:	00 
    11cd:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
    11d4:	00 
    11d5:	48 c7 45 e8 00 00 00 	movq   $0x0,-0x18(%rbp)
    11dc:	00 
    11dd:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    11e1:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    11e5:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    11e9:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    11ed:	48 8b 05 9c 0e 20 00 	mov    0x200e9c(%rip),%rax        # 202090 <ioctl_numbers+0x30>
    11f4:	48 89 c1             	mov    %rax,%rcx
    11f7:	8b 05 9b 0e 20 00    	mov    0x200e9b(%rip),%eax        # 202098 <fd>
    11fd:	48 8d 55 b0          	lea    -0x50(%rbp),%rdx
    1201:	48 89 ce             	mov    %rcx,%rsi
    1204:	89 c7                	mov    %eax,%edi
    1206:	b8 00 00 00 00       	mov    $0x0,%eax
    120b:	e8 50 f5 ff ff       	callq  760 <ioctl@plt>
    1210:	48 98                	cltq   
    1212:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
    1216:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
    121d:	00 00 
    121f:	74 05                	je     1226 <FlsSetValue+0xbc>
    1221:	e8 1a f5 ff ff       	callq  740 <__stack_chk_fail@plt>
    1226:	c9                   	leaveq 
    1227:	c3                   	retq   

0000000000001228 <FlsGetValue>:
    1228:	55                   	push   %rbp
    1229:	48 89 e5             	mov    %rsp,%rbp
    122c:	48 83 ec 60          	sub    $0x60,%rsp
    1230:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
    1234:	48 89 75 a0          	mov    %rsi,-0x60(%rbp)
    1238:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    123f:	00 00 
    1241:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1245:	31 c0                	xor    %eax,%eax
    1247:	8b 05 f3 0d 20 00    	mov    0x200df3(%rip),%eax        # 202040 <fiberlib_initialized>
    124d:	85 c0                	test   %eax,%eax
    124f:	75 0a                	jne    125b <FlsGetValue+0x33>
    1251:	b8 00 00 00 00       	mov    $0x0,%eax
    1256:	e8 71 fa ff ff       	callq  ccc <fiberlib_init>
    125b:	48 c7 45 b0 00 00 00 	movq   $0x0,-0x50(%rbp)
    1262:	00 
    1263:	48 c7 45 b8 00 00 00 	movq   $0x0,-0x48(%rbp)
    126a:	00 
    126b:	48 c7 45 c0 00 00 00 	movq   $0x0,-0x40(%rbp)
    1272:	00 
    1273:	48 c7 45 c8 00 00 00 	movq   $0x0,-0x38(%rbp)
    127a:	00 
    127b:	48 c7 45 d0 00 00 00 	movq   $0x0,-0x30(%rbp)
    1282:	00 
    1283:	48 c7 45 d8 00 00 00 	movq   $0x0,-0x28(%rbp)
    128a:	00 
    128b:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
    1292:	00 
    1293:	48 c7 45 e8 00 00 00 	movq   $0x0,-0x18(%rbp)
    129a:	00 
    129b:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    129f:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    12a3:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    12a7:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    12ab:	48 8b 05 d6 0d 20 00 	mov    0x200dd6(%rip),%rax        # 202088 <ioctl_numbers+0x28>
    12b2:	48 89 c1             	mov    %rax,%rcx
    12b5:	8b 05 dd 0d 20 00    	mov    0x200ddd(%rip),%eax        # 202098 <fd>
    12bb:	48 8d 55 b0          	lea    -0x50(%rbp),%rdx
    12bf:	48 89 ce             	mov    %rcx,%rsi
    12c2:	89 c7                	mov    %eax,%edi
    12c4:	b8 00 00 00 00       	mov    $0x0,%eax
    12c9:	e8 92 f4 ff ff       	callq  760 <ioctl@plt>
    12ce:	48 98                	cltq   
    12d0:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
    12d4:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
    12db:	00 00 
    12dd:	74 05                	je     12e4 <FlsGetValue+0xbc>
    12df:	e8 5c f4 ff ff       	callq  740 <__stack_chk_fail@plt>
    12e4:	c9                   	leaveq 
    12e5:	c3                   	retq   
    12e6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    12ed:	00 00 00 

00000000000012f0 <__libc_csu_init>:
    12f0:	41 57                	push   %r15
    12f2:	41 56                	push   %r14
    12f4:	49 89 d7             	mov    %rdx,%r15
    12f7:	41 55                	push   %r13
    12f9:	41 54                	push   %r12
    12fb:	4c 8d 25 6e 0a 20 00 	lea    0x200a6e(%rip),%r12        # 201d70 <__frame_dummy_init_array_entry>
    1302:	55                   	push   %rbp
    1303:	48 8d 2d 6e 0a 20 00 	lea    0x200a6e(%rip),%rbp        # 201d78 <__init_array_end>
    130a:	53                   	push   %rbx
    130b:	41 89 fd             	mov    %edi,%r13d
    130e:	49 89 f6             	mov    %rsi,%r14
    1311:	4c 29 e5             	sub    %r12,%rbp
    1314:	48 83 ec 08          	sub    $0x8,%rsp
    1318:	48 c1 fd 03          	sar    $0x3,%rbp
    131c:	e8 e7 f3 ff ff       	callq  708 <_init>
    1321:	48 85 ed             	test   %rbp,%rbp
    1324:	74 20                	je     1346 <__libc_csu_init+0x56>
    1326:	31 db                	xor    %ebx,%ebx
    1328:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    132f:	00 
    1330:	4c 89 fa             	mov    %r15,%rdx
    1333:	4c 89 f6             	mov    %r14,%rsi
    1336:	44 89 ef             	mov    %r13d,%edi
    1339:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
    133d:	48 83 c3 01          	add    $0x1,%rbx
    1341:	48 39 dd             	cmp    %rbx,%rbp
    1344:	75 ea                	jne    1330 <__libc_csu_init+0x40>
    1346:	48 83 c4 08          	add    $0x8,%rsp
    134a:	5b                   	pop    %rbx
    134b:	5d                   	pop    %rbp
    134c:	41 5c                	pop    %r12
    134e:	41 5d                	pop    %r13
    1350:	41 5e                	pop    %r14
    1352:	41 5f                	pop    %r15
    1354:	c3                   	retq   
    1355:	90                   	nop
    1356:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    135d:	00 00 00 

0000000000001360 <__libc_csu_fini>:
    1360:	f3 c3                	repz retq 

Disassemblamento della sezione .fini:

0000000000001364 <_fini>:
    1364:	48 83 ec 08          	sub    $0x8,%rsp
    1368:	48 83 c4 08          	add    $0x8,%rsp
    136c:	c3                   	retq   

Disassemblamento della sezione .rodata:

0000000000001380 <_IO_stdin_used>:
    1380:	01 00                	add    %eax,(%rax)
    1382:	02 00                	add    (%rax),%al
    1384:	00 00                	add    %al,(%rax)
    1386:	00 00                	add    %al,(%rax)
    1388:	53                   	push   %rbx
    1389:	74 61                	je     13ec <_IO_stdin_used+0x6c>
    138b:	72 74                	jb     1401 <_IO_stdin_used+0x81>
    138d:	69 6e 67 20 66 75 6e 	imul   $0x6e756620,0x67(%rsi),%ebp
    1394:	63 74 69 6f          	movslq 0x6f(%rcx,%rbp,2),%esi
    1398:	6e                   	outsb  %ds:(%rsi),(%dx)
    1399:	2e 2e 2e 00 00       	cs cs add %al,%cs:(%rax)
    139e:	00 00                	add    %al,(%rax)
    13a0:	50                   	push   %rax
    13a1:	61                   	(bad)  
    13a2:	72 61                	jb     1405 <_IO_stdin_used+0x85>
    13a4:	6d                   	insl   (%dx),%es:(%rdi)
    13a5:	65 74 65             	gs je  140d <_IO_stdin_used+0x8d>
    13a8:	72 73                	jb     141d <_IO_stdin_used+0x9d>
    13aa:	20 69 73             	and    %ch,0x73(%rcx)
    13ad:	20 25 63 20 61 6e    	and    %ah,0x6e612063(%rip)        # 6e613416 <_end+0x6e411376>
    13b3:	64 20 76 61          	and    %dh,%fs:0x61(%rsi)
    13b7:	6c                   	insb   (%dx),%es:(%rdi)
    13b8:	75 65                	jne    141f <_IO_stdin_used+0x9f>
    13ba:	20 69 73             	and    %ch,0x73(%rcx)
    13bd:	20 25 63 0a 00 63    	and    %ah,0x63000a63(%rip)        # 63001e26 <_end+0x62dffd86>
    13c3:	69 61 6f 00 63 69 61 	imul   $0x61696300,0x6f(%rcx),%esp
    13ca:	6f                   	outsl  %ds:(%rsi),(%dx)
    13cb:	2c 20                	sub    $0x20,%al
    13cd:	25 66 0a 00 62       	and    $0x62000a66,%eax
    13d2:	65 6c                	gs insb (%dx),%es:(%rdi)
    13d4:	6c                   	insb   (%dx),%es:(%rdi)
    13d5:	61                   	(bad)  
    13d6:	61                   	(bad)  
    13d7:	61                   	(bad)  
    13d8:	61                   	(bad)  
    13d9:	61                   	(bad)  
    13da:	61                   	(bad)  
    13db:	61                   	(bad)  
    13dc:	61                   	(bad)  
    13dd:	61                   	(bad)  
    13de:	61                   	(bad)  
    13df:	61                   	(bad)  
    13e0:	00 53 74             	add    %dl,0x74(%rbx)
    13e3:	61                   	(bad)  
    13e4:	72 74                	jb     145a <tab64+0x3a>
    13e6:	69 6e 67 20 6d 61 69 	imul   $0x69616d20,0x67(%rsi),%ebp
    13ed:	6e                   	outsb  %ds:(%rsi),(%dx)
    13ee:	2e 2e 2e 00 62 65    	cs cs add %ah,%cs:0x65(%rdx)
    13f4:	6c                   	insb   (%dx),%es:(%rdi)
    13f5:	6c                   	insb   (%dx),%es:(%rdi)
    13f6:	61                   	(bad)  
    13f7:	2c 20                	sub    $0x20,%al
    13f9:	25 66 0a 00 00       	and    $0xa66,%eax
    13fe:	00 00                	add    %al,(%rax)
    1400:	00 00                	add    %al,(%rax)
    1402:	00 3f                	add    %bh,(%rdi)
    1404:	00 00                	add    %al,(%rax)
    1406:	80 3f 33             	cmpb   $0x33,(%rdi)
    1409:	33 33                	xor    (%rbx),%esi
    140b:	33 33                	xor    (%rbx),%esi
    140d:	33 e3                	xor    %ebx,%esp
    140f:	3f                   	(bad)  
    1410:	00 00                	add    %al,(%rax)
    1412:	c0 3f 00             	sarb   $0x0,(%rdi)
	...
    141d:	00 e0                	add    %ah,%al
    141f:	3f                   	(bad)  

0000000000001420 <tab64>:
    1420:	3f                   	(bad)  
    1421:	00 00                	add    %al,(%rax)
    1423:	00 00                	add    %al,(%rax)
    1425:	00 00                	add    %al,(%rax)
    1427:	00 3a                	add    %bh,(%rdx)
    1429:	00 00                	add    %al,(%rax)
    142b:	00 01                	add    %al,(%rcx)
    142d:	00 00                	add    %al,(%rax)
    142f:	00 3b                	add    %bh,(%rbx)
    1431:	00 00                	add    %al,(%rax)
    1433:	00 2f                	add    %ch,(%rdi)
    1435:	00 00                	add    %al,(%rax)
    1437:	00 35 00 00 00 02    	add    %dh,0x2000000(%rip)        # 200143d <_end+0x1dff39d>
    143d:	00 00                	add    %al,(%rax)
    143f:	00 3c 00             	add    %bh,(%rax,%rax,1)
    1442:	00 00                	add    %al,(%rax)
    1444:	27                   	(bad)  
    1445:	00 00                	add    %al,(%rax)
    1447:	00 30                	add    %dh,(%rax)
    1449:	00 00                	add    %al,(%rax)
    144b:	00 1b                	add    %bl,(%rbx)
    144d:	00 00                	add    %al,(%rax)
    144f:	00 36                	add    %dh,(%rsi)
    1451:	00 00                	add    %al,(%rax)
    1453:	00 21                	add    %ah,(%rcx)
    1455:	00 00                	add    %al,(%rax)
    1457:	00 2a                	add    %ch,(%rdx)
    1459:	00 00                	add    %al,(%rax)
    145b:	00 03                	add    %al,(%rbx)
    145d:	00 00                	add    %al,(%rax)
    145f:	00 3d 00 00 00 33    	add    %bh,0x33000000(%rip)        # 33001465 <_end+0x32dff3c5>
    1465:	00 00                	add    %al,(%rax)
    1467:	00 25 00 00 00 28    	add    %ah,0x28000000(%rip)        # 2800146d <_end+0x27dff3cd>
    146d:	00 00                	add    %al,(%rax)
    146f:	00 31                	add    %dh,(%rcx)
    1471:	00 00                	add    %al,(%rax)
    1473:	00 12                	add    %dl,(%rdx)
    1475:	00 00                	add    %al,(%rax)
    1477:	00 1c 00             	add    %bl,(%rax,%rax,1)
    147a:	00 00                	add    %al,(%rax)
    147c:	14 00                	adc    $0x0,%al
    147e:	00 00                	add    %al,(%rax)
    1480:	37                   	(bad)  
    1481:	00 00                	add    %al,(%rax)
    1483:	00 1e                	add    %bl,(%rsi)
    1485:	00 00                	add    %al,(%rax)
    1487:	00 22                	add    %ah,(%rdx)
    1489:	00 00                	add    %al,(%rax)
    148b:	00 0b                	add    %cl,(%rbx)
    148d:	00 00                	add    %al,(%rax)
    148f:	00 2b                	add    %ch,(%rbx)
    1491:	00 00                	add    %al,(%rax)
    1493:	00 0e                	add    %cl,(%rsi)
    1495:	00 00                	add    %al,(%rax)
    1497:	00 16                	add    %dl,(%rsi)
    1499:	00 00                	add    %al,(%rax)
    149b:	00 04 00             	add    %al,(%rax,%rax,1)
    149e:	00 00                	add    %al,(%rax)
    14a0:	3e 00 00             	add    %al,%ds:(%rax)
    14a3:	00 39                	add    %bh,(%rcx)
    14a5:	00 00                	add    %al,(%rax)
    14a7:	00 2e                	add    %ch,(%rsi)
    14a9:	00 00                	add    %al,(%rax)
    14ab:	00 34 00             	add    %dh,(%rax,%rax,1)
    14ae:	00 00                	add    %al,(%rax)
    14b0:	26 00 00             	add    %al,%es:(%rax)
    14b3:	00 1a                	add    %bl,(%rdx)
    14b5:	00 00                	add    %al,(%rax)
    14b7:	00 20                	add    %ah,(%rax)
    14b9:	00 00                	add    %al,(%rax)
    14bb:	00 29                	add    %ch,(%rcx)
    14bd:	00 00                	add    %al,(%rax)
    14bf:	00 32                	add    %dh,(%rdx)
    14c1:	00 00                	add    %al,(%rax)
    14c3:	00 24 00             	add    %ah,(%rax,%rax,1)
    14c6:	00 00                	add    %al,(%rax)
    14c8:	11 00                	adc    %eax,(%rax)
    14ca:	00 00                	add    %al,(%rax)
    14cc:	13 00                	adc    (%rax),%eax
    14ce:	00 00                	add    %al,(%rax)
    14d0:	1d 00 00 00 0a       	sbb    $0xa000000,%eax
    14d5:	00 00                	add    %al,(%rax)
    14d7:	00 0d 00 00 00 15    	add    %cl,0x15000000(%rip)        # 150014dd <_end+0x14dff43d>
    14dd:	00 00                	add    %al,(%rax)
    14df:	00 38                	add    %bh,(%rax)
    14e1:	00 00                	add    %al,(%rax)
    14e3:	00 2d 00 00 00 19    	add    %ch,0x19000000(%rip)        # 190014e9 <_end+0x18dff449>
    14e9:	00 00                	add    %al,(%rax)
    14eb:	00 1f                	add    %bl,(%rdi)
    14ed:	00 00                	add    %al,(%rax)
    14ef:	00 23                	add    %ah,(%rbx)
    14f1:	00 00                	add    %al,(%rax)
    14f3:	00 10                	add    %dl,(%rax)
    14f5:	00 00                	add    %al,(%rax)
    14f7:	00 09                	add    %cl,(%rcx)
    14f9:	00 00                	add    %al,(%rax)
    14fb:	00 0c 00             	add    %cl,(%rax,%rax,1)
    14fe:	00 00                	add    %al,(%rax)
    1500:	2c 00                	sub    $0x0,%al
    1502:	00 00                	add    %al,(%rax)
    1504:	18 00                	sbb    %al,(%rax)
    1506:	00 00                	add    %al,(%rax)
    1508:	0f 00 00             	sldt   (%rax)
    150b:	00 08                	add    %cl,(%rax)
    150d:	00 00                	add    %al,(%rax)
    150f:	00 17                	add    %dl,(%rdi)
    1511:	00 00                	add    %al,(%rax)
    1513:	00 07                	add    %al,(%rdi)
    1515:	00 00                	add    %al,(%rax)
    1517:	00 06                	add    %al,(%rsi)
    1519:	00 00                	add    %al,(%rax)
    151b:	00 05 00 00 00 2f    	add    %al,0x2f000000(%rip)        # 2f001521 <_end+0x2edff481>
    1521:	64 65 76 2f          	fs gs jbe 1554 <__GNU_EH_FRAME_HDR+0x1c>
    1525:	66 69 62 65 72 73    	imul   $0x7372,0x65(%rdx),%sp
    152b:	00 00                	add    %al,(%rax)
    152d:	00 00                	add    %al,(%rax)
    152f:	00 9a 99 99 99 99    	add    %bl,-0x66666667(%rdx)
    1535:	99                   	cltd   
    1536:	a9                   	.byte 0xa9
    1537:	3f                   	(bad)  

Disassemblamento della sezione .eh_frame_hdr:

0000000000001538 <__GNU_EH_FRAME_HDR>:
    1538:	01 1b                	add    %ebx,(%rbx)
    153a:	03 3b                	add    (%rbx),%edi
    153c:	8c 00                	mov    %es,(%rax)
    153e:	00 00                	add    %al,(%rax)
    1540:	10 00                	adc    %al,(%rax)
    1542:	00 00                	add    %al,(%rax)
    1544:	e8 f1 ff ff d8       	callq  ffffffffd900153a <_end+0xffffffffd8dff49a>
    1549:	00 00                	add    %al,(%rax)
    154b:	00 98 f2 ff ff 00    	add    %bl,0xfffff2(%rax)
    1551:	01 00                	add    %eax,(%rax)
    1553:	00 a8 f2 ff ff a8    	add    %ch,-0x5700000e(%rax)
    1559:	00 00                	add    %al,(%rax)
    155b:	00 b2 f3 ff ff 18    	add    %dh,0x18fffff3(%rdx)
    1561:	01 00                	add    %eax,(%rax)
    1563:	00 87 f5 ff ff 34    	add    %al,0x34fffff5(%rdi)
    1569:	01 00                	add    %eax,(%rax)
    156b:	00 0b                	add    %cl,(%rbx)
    156d:	f7 ff                	idiv   %edi
    156f:	ff 50 01             	callq  *0x1(%rax)
    1572:	00 00                	add    %al,(%rax)
    1574:	94                   	xchg   %eax,%esp
    1575:	f7 ff                	idiv   %edi
    1577:	ff 70 01             	pushq  0x1(%rax)
    157a:	00 00                	add    %al,(%rax)
    157c:	d3 f8                	sar    %cl,%eax
    157e:	ff                   	(bad)  
    157f:	ff 90 01 00 00 11    	callq  *0x11000001(%rax)
    1585:	f9                   	stc    
    1586:	ff                   	(bad)  
    1587:	ff b0 01 00 00 1f    	pushq  0x1f000001(%rax)
    158d:	fa                   	cli    
    158e:	ff                   	(bad)  
    158f:	ff d0                	callq  *%rax
    1591:	01 00                	add    %eax,(%rax)
    1593:	00 ce                	add    %cl,%dh
    1595:	fa                   	cli    
    1596:	ff                   	(bad)  
    1597:	ff f0                	push   %rax
    1599:	01 00                	add    %eax,(%rax)
    159b:	00 80 fb ff ff 10    	add    %al,0x10fffffb(%rax)
    15a1:	02 00                	add    (%rax),%al
    15a3:	00 32                	add    %dh,(%rdx)
    15a5:	fc                   	cld    
    15a6:	ff                   	(bad)  
    15a7:	ff 30                	pushq  (%rax)
    15a9:	02 00                	add    (%rax),%al
    15ab:	00 f0                	add    %dh,%al
    15ad:	fc                   	cld    
    15ae:	ff                   	(bad)  
    15af:	ff 50 02             	callq  *0x2(%rax)
    15b2:	00 00                	add    %al,(%rax)
    15b4:	b8 fd ff ff 70       	mov    $0x70fffffd,%eax
    15b9:	02 00                	add    (%rax),%al
    15bb:	00 28                	add    %ch,(%rax)
    15bd:	fe                   	(bad)  
    15be:	ff                   	(bad)  
    15bf:	ff                   	(bad)  
    15c0:	b8                   	.byte 0xb8
    15c1:	02 00                	add    (%rax),%al
	...

Disassemblamento della sezione .eh_frame:

00000000000015c8 <__FRAME_END__-0x23c>:
    15c8:	14 00                	adc    $0x0,%al
    15ca:	00 00                	add    %al,(%rax)
    15cc:	00 00                	add    %al,(%rax)
    15ce:	00 00                	add    %al,(%rax)
    15d0:	01 7a 52             	add    %edi,0x52(%rdx)
    15d3:	00 01                	add    %al,(%rcx)
    15d5:	78 10                	js     15e7 <__GNU_EH_FRAME_HDR+0xaf>
    15d7:	01 1b                	add    %ebx,(%rbx)
    15d9:	0c 07                	or     $0x7,%al
    15db:	08 90 01 07 10 14    	or     %dl,0x14100701(%rax)
    15e1:	00 00                	add    %al,(%rax)
    15e3:	00 1c 00             	add    %bl,(%rax,%rax,1)
    15e6:	00 00                	add    %al,(%rax)
    15e8:	f8                   	clc    
    15e9:	f1                   	icebp  
    15ea:	ff                   	(bad)  
    15eb:	ff 2b                	ljmp   *(%rbx)
	...
    15f5:	00 00                	add    %al,(%rax)
    15f7:	00 14 00             	add    %dl,(%rax,%rax,1)
    15fa:	00 00                	add    %al,(%rax)
    15fc:	00 00                	add    %al,(%rax)
    15fe:	00 00                	add    %al,(%rax)
    1600:	01 7a 52             	add    %edi,0x52(%rdx)
    1603:	00 01                	add    %al,(%rcx)
    1605:	78 10                	js     1617 <__GNU_EH_FRAME_HDR+0xdf>
    1607:	01 1b                	add    %ebx,(%rbx)
    1609:	0c 07                	or     $0x7,%al
    160b:	08 90 01 00 00 24    	or     %dl,0x24000001(%rax)
    1611:	00 00                	add    %al,(%rax)
    1613:	00 1c 00             	add    %bl,(%rax,%rax,1)
    1616:	00 00                	add    %al,(%rax)
    1618:	08 f1                	or     %dh,%cl
    161a:	ff                   	(bad)  
    161b:	ff b0 00 00 00 00    	pushq  0x0(%rax)
    1621:	0e                   	(bad)  
    1622:	10 46 0e             	adc    %al,0xe(%rsi)
    1625:	18 4a 0f             	sbb    %cl,0xf(%rdx)
    1628:	0b 77 08             	or     0x8(%rdi),%esi
    162b:	80 00 3f             	addb   $0x3f,(%rax)
    162e:	1a 3b                	sbb    (%rbx),%bh
    1630:	2a 33                	sub    (%rbx),%dh
    1632:	24 22                	and    $0x22,%al
    1634:	00 00                	add    %al,(%rax)
    1636:	00 00                	add    %al,(%rax)
    1638:	14 00                	adc    $0x0,%al
    163a:	00 00                	add    %al,(%rax)
    163c:	44 00 00             	add    %r8b,(%rax)
    163f:	00 90 f1 ff ff 08    	add    %dl,0x8fffff1(%rax)
	...
    164d:	00 00                	add    %al,(%rax)
    164f:	00 18                	add    %bl,(%rax)
    1651:	00 00                	add    %al,(%rax)
    1653:	00 5c 00 00          	add    %bl,0x0(%rax,%rax,1)
    1657:	00 92 f2 ff ff d5    	add    %dl,-0x2a00000e(%rdx)
    165d:	01 00                	add    %eax,(%rax)
    165f:	00 00                	add    %al,(%rax)
    1661:	41 0e                	rex.B (bad) 
    1663:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    1669:	00 00                	add    %al,(%rax)
    166b:	00 18                	add    %bl,(%rax)
    166d:	00 00                	add    %al,(%rax)
    166f:	00 78 00             	add    %bh,0x0(%rax)
    1672:	00 00                	add    %al,(%rax)
    1674:	4b f4                	rex.WXB hlt 
    1676:	ff                   	(bad)  
    1677:	ff 84 01 00 00 00 41 	incl   0x41000000(%rcx,%rax,1)
    167e:	0e                   	(bad)  
    167f:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    1685:	00 00                	add    %al,(%rax)
    1687:	00 1c 00             	add    %bl,(%rax,%rax,1)
    168a:	00 00                	add    %al,(%rax)
    168c:	94                   	xchg   %eax,%esp
    168d:	00 00                	add    %al,(%rax)
    168f:	00 b3 f5 ff ff 89    	add    %dh,-0x7600000b(%rbx)
    1695:	00 00                	add    %al,(%rax)
    1697:	00 00                	add    %al,(%rax)
    1699:	41 0e                	rex.B (bad) 
    169b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    16a1:	02 84 0c 07 08 00 00 	add    0x807(%rsp,%rcx,1),%al
    16a8:	1c 00                	sbb    $0x0,%al
    16aa:	00 00                	add    %al,(%rax)
    16ac:	b4 00                	mov    $0x0,%ah
    16ae:	00 00                	add    %al,(%rax)
    16b0:	1c f6                	sbb    $0xf6,%al
    16b2:	ff                   	(bad)  
    16b3:	ff                   	(bad)  
    16b4:	3f                   	(bad)  
    16b5:	01 00                	add    %eax,(%rax)
    16b7:	00 00                	add    %al,(%rax)
    16b9:	41 0e                	rex.B (bad) 
    16bb:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    16c1:	03 3a                	add    (%rdx),%edi
    16c3:	01 0c 07             	add    %ecx,(%rdi,%rax,1)
    16c6:	08 00                	or     %al,(%rax)
    16c8:	1c 00                	sbb    $0x0,%al
    16ca:	00 00                	add    %al,(%rax)
    16cc:	d4                   	(bad)  
    16cd:	00 00                	add    %al,(%rax)
    16cf:	00 3b                	add    %bh,(%rbx)
    16d1:	f7 ff                	idiv   %edi
    16d3:	ff                   	(bad)  
    16d4:	3e 00 00             	add    %al,%ds:(%rax)
    16d7:	00 00                	add    %al,(%rax)
    16d9:	41 0e                	rex.B (bad) 
    16db:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    16e1:	79 0c                	jns    16ef <__GNU_EH_FRAME_HDR+0x1b7>
    16e3:	07                   	(bad)  
    16e4:	08 00                	or     %al,(%rax)
    16e6:	00 00                	add    %al,(%rax)
    16e8:	1c 00                	sbb    $0x0,%al
    16ea:	00 00                	add    %al,(%rax)
    16ec:	f4                   	hlt    
    16ed:	00 00                	add    %al,(%rax)
    16ef:	00 59 f7             	add    %bl,-0x9(%rcx)
    16f2:	ff                   	(bad)  
    16f3:	ff 0e                	decl   (%rsi)
    16f5:	01 00                	add    %eax,(%rax)
    16f7:	00 00                	add    %al,(%rax)
    16f9:	41 0e                	rex.B (bad) 
    16fb:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    1701:	03 09                	add    (%rcx),%ecx
    1703:	01 0c 07             	add    %ecx,(%rdi,%rax,1)
    1706:	08 00                	or     %al,(%rax)
    1708:	1c 00                	sbb    $0x0,%al
    170a:	00 00                	add    %al,(%rax)
    170c:	14 01                	adc    $0x1,%al
    170e:	00 00                	add    %al,(%rax)
    1710:	47 f8                	rex.RXB clc 
    1712:	ff                   	(bad)  
    1713:	ff af 00 00 00 00    	ljmp   *0x0(%rdi)
    1719:	41 0e                	rex.B (bad) 
    171b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    1721:	02 aa 0c 07 08 00    	add    0x8070c(%rdx),%ch
    1727:	00 1c 00             	add    %bl,(%rax,%rax,1)
    172a:	00 00                	add    %al,(%rax)
    172c:	34 01                	xor    $0x1,%al
    172e:	00 00                	add    %al,(%rax)
    1730:	d6                   	(bad)  
    1731:	f8                   	clc    
    1732:	ff                   	(bad)  
    1733:	ff b2 00 00 00 00    	pushq  0x0(%rdx)
    1739:	41 0e                	rex.B (bad) 
    173b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    1741:	02 ad 0c 07 08 00    	add    0x8070c(%rbp),%ch
    1747:	00 1c 00             	add    %bl,(%rax,%rax,1)
    174a:	00 00                	add    %al,(%rax)
    174c:	54                   	push   %rsp
    174d:	01 00                	add    %eax,(%rax)
    174f:	00 68 f9             	add    %ch,-0x7(%rax)
    1752:	ff                   	(bad)  
    1753:	ff b2 00 00 00 00    	pushq  0x0(%rdx)
    1759:	41 0e                	rex.B (bad) 
    175b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    1761:	02 ad 0c 07 08 00    	add    0x8070c(%rbp),%ch
    1767:	00 1c 00             	add    %bl,(%rax,%rax,1)
    176a:	00 00                	add    %al,(%rax)
    176c:	74 01                	je     176f <__GNU_EH_FRAME_HDR+0x237>
    176e:	00 00                	add    %al,(%rax)
    1770:	fa                   	cli    
    1771:	f9                   	stc    
    1772:	ff                   	(bad)  
    1773:	ff                   	(bad)  
    1774:	be 00 00 00 00       	mov    $0x0,%esi
    1779:	41 0e                	rex.B (bad) 
    177b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    1781:	02 b9 0c 07 08 00    	add    0x8070c(%rcx),%bh
    1787:	00 1c 00             	add    %bl,(%rax,%rax,1)
    178a:	00 00                	add    %al,(%rax)
    178c:	94                   	xchg   %eax,%esp
    178d:	01 00                	add    %eax,(%rax)
    178f:	00 98 fa ff ff be    	add    %bl,-0x41000006(%rax)
    1795:	00 00                	add    %al,(%rax)
    1797:	00 00                	add    %al,(%rax)
    1799:	41 0e                	rex.B (bad) 
    179b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    17a1:	02 b9 0c 07 08 00    	add    0x8070c(%rcx),%bh
    17a7:	00 44 00 00          	add    %al,0x0(%rax,%rax,1)
    17ab:	00 b4 01 00 00 40 fb 	add    %dh,-0x4c00000(%rcx,%rax,1)
    17b2:	ff                   	(bad)  
    17b3:	ff 65 00             	jmpq   *0x0(%rbp)
    17b6:	00 00                	add    %al,(%rax)
    17b8:	00 42 0e             	add    %al,0xe(%rdx)
    17bb:	10 8f 02 42 0e 18    	adc    %cl,0x180e4202(%rdi)
    17c1:	8e 03                	mov    (%rbx),%es
    17c3:	45 0e                	rex.RB (bad) 
    17c5:	20 8d 04 42 0e 28    	and    %cl,0x280e4204(%rbp)
    17cb:	8c 05 48 0e 30 86    	mov    %es,-0x79cff1b8(%rip)        # ffffffff86302619 <_end+0xffffffff86100579>
    17d1:	06                   	(bad)  
    17d2:	48 0e                	rex.W (bad) 
    17d4:	38 83 07 4d 0e 40    	cmp    %al,0x400e4d07(%rbx)
    17da:	72 0e                	jb     17ea <__GNU_EH_FRAME_HDR+0x2b2>
    17dc:	38 41 0e             	cmp    %al,0xe(%rcx)
    17df:	30 41 0e             	xor    %al,0xe(%rcx)
    17e2:	28 42 0e             	sub    %al,0xe(%rdx)
    17e5:	20 42 0e             	and    %al,0xe(%rdx)
    17e8:	18 42 0e             	sbb    %al,0xe(%rdx)
    17eb:	10 42 0e             	adc    %al,0xe(%rdx)
    17ee:	08 00                	or     %al,(%rax)
    17f0:	10 00                	adc    %al,(%rax)
    17f2:	00 00                	add    %al,(%rax)
    17f4:	fc                   	cld    
    17f5:	01 00                	add    %eax,(%rax)
    17f7:	00 68 fb             	add    %ch,-0x5(%rax)
    17fa:	ff                   	(bad)  
    17fb:	ff 02                	incl   (%rdx)
    17fd:	00 00                	add    %al,(%rax)
    17ff:	00 00                	add    %al,(%rax)
    1801:	00 00                	add    %al,(%rax)
	...

0000000000001804 <__FRAME_END__>:
    1804:	00 00                	add    %al,(%rax)
	...

Disassemblamento della sezione .init_array:

0000000000201d70 <__frame_dummy_init_array_entry>:
  201d70:	e0 08                	loopne 201d7a <__init_array_end+0x2>
  201d72:	00 00                	add    %al,(%rax)
  201d74:	00 00                	add    %al,(%rax)
	...

Disassemblamento della sezione .fini_array:

0000000000201d78 <__do_global_dtors_aux_fini_array_entry>:
  201d78:	a0                   	.byte 0xa0
  201d79:	08 00                	or     %al,(%rax)
  201d7b:	00 00                	add    %al,(%rax)
  201d7d:	00 00                	add    %al,(%rax)
	...

Disassemblamento della sezione .dynamic:

0000000000201d80 <_DYNAMIC>:
  201d80:	01 00                	add    %eax,(%rax)
  201d82:	00 00                	add    %al,(%rax)
  201d84:	00 00                	add    %al,(%rax)
  201d86:	00 00                	add    %al,(%rax)
  201d88:	01 00                	add    %eax,(%rax)
  201d8a:	00 00                	add    %al,(%rax)
  201d8c:	00 00                	add    %al,(%rax)
  201d8e:	00 00                	add    %al,(%rax)
  201d90:	0c 00                	or     $0x0,%al
  201d92:	00 00                	add    %al,(%rax)
  201d94:	00 00                	add    %al,(%rax)
  201d96:	00 00                	add    %al,(%rax)
  201d98:	08 07                	or     %al,(%rdi)
  201d9a:	00 00                	add    %al,(%rax)
  201d9c:	00 00                	add    %al,(%rax)
  201d9e:	00 00                	add    %al,(%rax)
  201da0:	0d 00 00 00 00       	or     $0x0,%eax
  201da5:	00 00                	add    %al,(%rax)
  201da7:	00 64 13 00          	add    %ah,0x0(%rbx,%rdx,1)
  201dab:	00 00                	add    %al,(%rax)
  201dad:	00 00                	add    %al,(%rax)
  201daf:	00 19                	add    %bl,(%rcx)
  201db1:	00 00                	add    %al,(%rax)
  201db3:	00 00                	add    %al,(%rax)
  201db5:	00 00                	add    %al,(%rax)
  201db7:	00 70 1d             	add    %dh,0x1d(%rax)
  201dba:	20 00                	and    %al,(%rax)
  201dbc:	00 00                	add    %al,(%rax)
  201dbe:	00 00                	add    %al,(%rax)
  201dc0:	1b 00                	sbb    (%rax),%eax
  201dc2:	00 00                	add    %al,(%rax)
  201dc4:	00 00                	add    %al,(%rax)
  201dc6:	00 00                	add    %al,(%rax)
  201dc8:	08 00                	or     %al,(%rax)
  201dca:	00 00                	add    %al,(%rax)
  201dcc:	00 00                	add    %al,(%rax)
  201dce:	00 00                	add    %al,(%rax)
  201dd0:	1a 00                	sbb    (%rax),%al
  201dd2:	00 00                	add    %al,(%rax)
  201dd4:	00 00                	add    %al,(%rax)
  201dd6:	00 00                	add    %al,(%rax)
  201dd8:	78 1d                	js     201df7 <_DYNAMIC+0x77>
  201dda:	20 00                	and    %al,(%rax)
  201ddc:	00 00                	add    %al,(%rax)
  201dde:	00 00                	add    %al,(%rax)
  201de0:	1c 00                	sbb    $0x0,%al
  201de2:	00 00                	add    %al,(%rax)
  201de4:	00 00                	add    %al,(%rax)
  201de6:	00 00                	add    %al,(%rax)
  201de8:	08 00                	or     %al,(%rax)
  201dea:	00 00                	add    %al,(%rax)
  201dec:	00 00                	add    %al,(%rax)
  201dee:	00 00                	add    %al,(%rax)
  201df0:	f5                   	cmc    
  201df1:	fe                   	(bad)  
  201df2:	ff 6f 00             	ljmp   *0x0(%rdi)
  201df5:	00 00                	add    %al,(%rax)
  201df7:	00 98 02 00 00 00    	add    %bl,0x2(%rax)
  201dfd:	00 00                	add    %al,(%rax)
  201dff:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 201e05 <_DYNAMIC+0x85>
  201e05:	00 00                	add    %al,(%rax)
  201e07:	00 38                	add    %bh,(%rax)
  201e09:	04 00                	add    $0x0,%al
  201e0b:	00 00                	add    %al,(%rax)
  201e0d:	00 00                	add    %al,(%rax)
  201e0f:	00 06                	add    %al,(%rsi)
  201e11:	00 00                	add    %al,(%rax)
  201e13:	00 00                	add    %al,(%rax)
  201e15:	00 00                	add    %al,(%rax)
  201e17:	00 b8 02 00 00 00    	add    %bh,0x2(%rax)
  201e1d:	00 00                	add    %al,(%rax)
  201e1f:	00 0a                	add    %cl,(%rdx)
  201e21:	00 00                	add    %al,(%rax)
  201e23:	00 00                	add    %al,(%rax)
  201e25:	00 00                	add    %al,(%rax)
  201e27:	00 ce                	add    %cl,%dh
  201e29:	00 00                	add    %al,(%rax)
  201e2b:	00 00                	add    %al,(%rax)
  201e2d:	00 00                	add    %al,(%rax)
  201e2f:	00 0b                	add    %cl,(%rbx)
  201e31:	00 00                	add    %al,(%rax)
  201e33:	00 00                	add    %al,(%rax)
  201e35:	00 00                	add    %al,(%rax)
  201e37:	00 18                	add    %bl,(%rax)
  201e39:	00 00                	add    %al,(%rax)
  201e3b:	00 00                	add    %al,(%rax)
  201e3d:	00 00                	add    %al,(%rax)
  201e3f:	00 15 00 00 00 00    	add    %dl,0x0(%rip)        # 201e45 <_DYNAMIC+0xc5>
	...
  201e4d:	00 00                	add    %al,(%rax)
  201e4f:	00 03                	add    %al,(%rbx)
  201e51:	00 00                	add    %al,(%rax)
  201e53:	00 00                	add    %al,(%rax)
  201e55:	00 00                	add    %al,(%rax)
  201e57:	00 70 1f             	add    %dh,0x1f(%rax)
  201e5a:	20 00                	and    %al,(%rax)
  201e5c:	00 00                	add    %al,(%rax)
  201e5e:	00 00                	add    %al,(%rax)
  201e60:	02 00                	add    (%rax),%al
  201e62:	00 00                	add    %al,(%rax)
  201e64:	00 00                	add    %al,(%rax)
  201e66:	00 00                	add    %al,(%rax)
  201e68:	f0 00 00             	lock add %al,(%rax)
  201e6b:	00 00                	add    %al,(%rax)
  201e6d:	00 00                	add    %al,(%rax)
  201e6f:	00 14 00             	add    %dl,(%rax,%rax,1)
  201e72:	00 00                	add    %al,(%rax)
  201e74:	00 00                	add    %al,(%rax)
  201e76:	00 00                	add    %al,(%rax)
  201e78:	07                   	(bad)  
  201e79:	00 00                	add    %al,(%rax)
  201e7b:	00 00                	add    %al,(%rax)
  201e7d:	00 00                	add    %al,(%rax)
  201e7f:	00 17                	add    %dl,(%rdi)
  201e81:	00 00                	add    %al,(%rax)
  201e83:	00 00                	add    %al,(%rax)
  201e85:	00 00                	add    %al,(%rax)
  201e87:	00 18                	add    %bl,(%rax)
  201e89:	06                   	(bad)  
  201e8a:	00 00                	add    %al,(%rax)
  201e8c:	00 00                	add    %al,(%rax)
  201e8e:	00 00                	add    %al,(%rax)
  201e90:	07                   	(bad)  
  201e91:	00 00                	add    %al,(%rax)
  201e93:	00 00                	add    %al,(%rax)
  201e95:	00 00                	add    %al,(%rax)
  201e97:	00 58 05             	add    %bl,0x5(%rax)
  201e9a:	00 00                	add    %al,(%rax)
  201e9c:	00 00                	add    %al,(%rax)
  201e9e:	00 00                	add    %al,(%rax)
  201ea0:	08 00                	or     %al,(%rax)
  201ea2:	00 00                	add    %al,(%rax)
  201ea4:	00 00                	add    %al,(%rax)
  201ea6:	00 00                	add    %al,(%rax)
  201ea8:	c0 00 00             	rolb   $0x0,(%rax)
  201eab:	00 00                	add    %al,(%rax)
  201ead:	00 00                	add    %al,(%rax)
  201eaf:	00 09                	add    %cl,(%rcx)
  201eb1:	00 00                	add    %al,(%rax)
  201eb3:	00 00                	add    %al,(%rax)
  201eb5:	00 00                	add    %al,(%rax)
  201eb7:	00 18                	add    %bl,(%rax)
  201eb9:	00 00                	add    %al,(%rax)
  201ebb:	00 00                	add    %al,(%rax)
  201ebd:	00 00                	add    %al,(%rax)
  201ebf:	00 1e                	add    %bl,(%rsi)
  201ec1:	00 00                	add    %al,(%rax)
  201ec3:	00 00                	add    %al,(%rax)
  201ec5:	00 00                	add    %al,(%rax)
  201ec7:	00 08                	add    %cl,(%rax)
  201ec9:	00 00                	add    %al,(%rax)
  201ecb:	00 00                	add    %al,(%rax)
  201ecd:	00 00                	add    %al,(%rax)
  201ecf:	00 fb                	add    %bh,%bl
  201ed1:	ff                   	(bad)  
  201ed2:	ff 6f 00             	ljmp   *0x0(%rdi)
  201ed5:	00 00                	add    %al,(%rax)
  201ed7:	00 01                	add    %al,(%rcx)
  201ed9:	00 00                	add    %al,(%rax)
  201edb:	08 00                	or     %al,(%rax)
  201edd:	00 00                	add    %al,(%rax)
  201edf:	00 fe                	add    %bh,%dh
  201ee1:	ff                   	(bad)  
  201ee2:	ff 6f 00             	ljmp   *0x0(%rdi)
  201ee5:	00 00                	add    %al,(%rax)
  201ee7:	00 28                	add    %ch,(%rax)
  201ee9:	05 00 00 00 00       	add    $0x0,%eax
  201eee:	00 00                	add    %al,(%rax)
  201ef0:	ff                   	(bad)  
  201ef1:	ff                   	(bad)  
  201ef2:	ff 6f 00             	ljmp   *0x0(%rdi)
  201ef5:	00 00                	add    %al,(%rax)
  201ef7:	00 01                	add    %al,(%rcx)
  201ef9:	00 00                	add    %al,(%rax)
  201efb:	00 00                	add    %al,(%rax)
  201efd:	00 00                	add    %al,(%rax)
  201eff:	00 f0                	add    %dh,%al
  201f01:	ff                   	(bad)  
  201f02:	ff 6f 00             	ljmp   *0x0(%rdi)
  201f05:	00 00                	add    %al,(%rax)
  201f07:	00 06                	add    %al,(%rsi)
  201f09:	05 00 00 00 00       	add    $0x0,%eax
  201f0e:	00 00                	add    %al,(%rax)
  201f10:	f9                   	stc    
  201f11:	ff                   	(bad)  
  201f12:	ff 6f 00             	ljmp   *0x0(%rdi)
  201f15:	00 00                	add    %al,(%rax)
  201f17:	00 03                	add    %al,(%rbx)
	...

Disassemblamento della sezione .got:

0000000000201f70 <_GLOBAL_OFFSET_TABLE_>:
  201f70:	80 1d 20 00 00 00 00 	sbbb   $0x0,0x20(%rip)        # 201f97 <_GLOBAL_OFFSET_TABLE_+0x27>
	...
  201f87:	00 36                	add    %dh,(%rsi)
  201f89:	07                   	(bad)  
  201f8a:	00 00                	add    %al,(%rax)
  201f8c:	00 00                	add    %al,(%rax)
  201f8e:	00 00                	add    %al,(%rax)
  201f90:	46 07                	rex.RX (bad) 
  201f92:	00 00                	add    %al,(%rax)
  201f94:	00 00                	add    %al,(%rax)
  201f96:	00 00                	add    %al,(%rax)
  201f98:	56                   	push   %rsi
  201f99:	07                   	(bad)  
  201f9a:	00 00                	add    %al,(%rax)
  201f9c:	00 00                	add    %al,(%rax)
  201f9e:	00 00                	add    %al,(%rax)
  201fa0:	66 07                	data16 (bad) 
  201fa2:	00 00                	add    %al,(%rax)
  201fa4:	00 00                	add    %al,(%rax)
  201fa6:	00 00                	add    %al,(%rax)
  201fa8:	76 07                	jbe    201fb1 <_GLOBAL_OFFSET_TABLE_+0x41>
  201faa:	00 00                	add    %al,(%rax)
  201fac:	00 00                	add    %al,(%rax)
  201fae:	00 00                	add    %al,(%rax)
  201fb0:	86 07                	xchg   %al,(%rdi)
  201fb2:	00 00                	add    %al,(%rax)
  201fb4:	00 00                	add    %al,(%rax)
  201fb6:	00 00                	add    %al,(%rax)
  201fb8:	96                   	xchg   %eax,%esi
  201fb9:	07                   	(bad)  
  201fba:	00 00                	add    %al,(%rax)
  201fbc:	00 00                	add    %al,(%rax)
  201fbe:	00 00                	add    %al,(%rax)
  201fc0:	a6                   	cmpsb  %es:(%rdi),%ds:(%rsi)
  201fc1:	07                   	(bad)  
  201fc2:	00 00                	add    %al,(%rax)
  201fc4:	00 00                	add    %al,(%rax)
  201fc6:	00 00                	add    %al,(%rax)
  201fc8:	b6 07                	mov    $0x7,%dh
  201fca:	00 00                	add    %al,(%rax)
  201fcc:	00 00                	add    %al,(%rax)
  201fce:	00 00                	add    %al,(%rax)
  201fd0:	c6 07 00             	movb   $0x0,(%rdi)
	...

Disassemblamento della sezione .data:

0000000000202000 <__data_start>:
	...

0000000000202008 <__dso_handle>:
  202008:	08 20                	or     %ah,(%rax)
  20200a:	20 00                	and    %al,(%rax)
  20200c:	00 00                	add    %al,(%rax)
	...

Disassemblamento della sezione .bss:

0000000000202020 <completed.7696>:
	...

0000000000202040 <fiberlib_initialized>:
	...

0000000000202060 <ioctl_numbers>:
	...

0000000000202098 <fd>:
	...

Disassemblamento della sezione .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 55 62             	sub    %dl,0x62(%rbp)
   8:	75 6e                	jne    78 <_init-0x690>
   a:	74 75                	je     81 <_init-0x687>
   c:	20 37                	and    %dh,(%rdi)
   e:	2e 33 2e             	xor    %cs:(%rsi),%ebp
  11:	30 2d 31 36 75 62    	xor    %ch,0x62753631(%rip)        # 62753648 <_end+0x625515a8>
  17:	75 6e                	jne    87 <_init-0x681>
  19:	74 75                	je     90 <_init-0x678>
  1b:	33 29                	xor    (%rcx),%ebp
  1d:	20 37                	and    %dh,(%rdi)
  1f:	2e 33 2e             	xor    %cs:(%rsi),%ebp
  22:	30 00                	xor    %al,(%rax)
