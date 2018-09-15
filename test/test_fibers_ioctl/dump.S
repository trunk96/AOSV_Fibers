
a.out:     formato del file elf64-x86-64


Disassemblamento della sezione .interp:

0000000000000238 <.interp>:
 238:	2f                   	(bad)  
 239:	6c                   	insb   (%dx),%es:(%rdi)
 23a:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
 241:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
 246:	78 2d                	js     275 <_init-0x463>
 248:	78 38                	js     282 <_init-0x456>
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
 283:	00 8a 70 63 30 27    	add    %cl,0x27306370(%rdx)
 289:	97                   	xchg   %eax,%edi
 28a:	41 19 e6             	sbb    %esp,%r14d
 28d:	75 ca                	jne    259 <_init-0x47f>
 28f:	fb                   	sti    
 290:	2f                   	(bad)  
 291:	0e                   	(bad)  
 292:	e4 90                	in     $0x90,%al
 294:	ce                   	(bad)  
 295:	90                   	nop
 296:	ba                   	.byte 0xba
 297:	99                   	cltd   

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
 2d0:	86 00                	xchg   %al,(%rax)
 2d2:	00 00                	add    %al,(%rax)
 2d4:	20 00                	and    %al,(%rax)
	...
 2e6:	00 00                	add    %al,(%rax)
 2e8:	1c 00                	sbb    $0x0,%al
 2ea:	00 00                	add    %al,(%rax)
 2ec:	12 00                	adc    (%rax),%al
	...
 2fe:	00 00                	add    %al,(%rax)
 300:	0b 00                	or     (%rax),%eax
 302:	00 00                	add    %al,(%rax)
 304:	12 00                	adc    (%rax),%al
	...
 316:	00 00                	add    %al,(%rax)
 318:	23 00                	and    (%rax),%eax
 31a:	00 00                	add    %al,(%rax)
 31c:	12 00                	adc    (%rax),%al
	...
 32e:	00 00                	add    %al,(%rax)
 330:	44 00 00             	add    %r8b,(%rax)
 333:	00 12                	add    %dl,(%rdx)
	...
 345:	00 00                	add    %al,(%rax)
 347:	00 38                	add    %bh,(%rax)
 349:	00 00                	add    %al,(%rax)
 34b:	00 12                	add    %dl,(%rdx)
	...
 35d:	00 00                	add    %al,(%rax)
 35f:	00 5e 00             	add    %bl,0x0(%rsi)
 362:	00 00                	add    %al,(%rax)
 364:	12 00                	adc    (%rax),%al
	...
 376:	00 00                	add    %al,(%rax)
 378:	a2 00 00 00 20 00 00 	movabs %al,0x20000000
 37f:	00 00 
	...
 38d:	00 00                	add    %al,(%rax)
 38f:	00 31                	add    %dh,(%rcx)
 391:	00 00                	add    %al,(%rax)
 393:	00 12                	add    %dl,(%rdx)
	...
 3a5:	00 00                	add    %al,(%rax)
 3a7:	00 3d 00 00 00 12    	add    %bh,0x12000000(%rip)        # 120003ad <_end+0x11dfe395>
	...
 3bd:	00 00                	add    %al,(%rax)
 3bf:	00 4a 00             	add    %cl,0x0(%rdx)
 3c2:	00 00                	add    %al,(%rax)
 3c4:	12 00                	adc    (%rax),%al
	...
 3d6:	00 00                	add    %al,(%rax)
 3d8:	2a 00                	sub    (%rax),%al
 3da:	00 00                	add    %al,(%rax)
 3dc:	12 00                	adc    (%rax),%al
	...
 3ee:	00 00                	add    %al,(%rax)
 3f0:	b1 00                	mov    $0x0,%cl
 3f2:	00 00                	add    %al,(%rax)
 3f4:	20 00                	and    %al,(%rax)
	...
 406:	00 00                	add    %al,(%rax)
 408:	4f 00 00             	rex.WRXB add %r8b,(%r8)
 40b:	00 22                	add    %ah,(%rdx)
	...

Disassemblamento della sezione .dynstr:

0000000000000420 <.dynstr>:
 420:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
 424:	63 2e                	movslq (%rsi),%ebp
 426:	73 6f                	jae    497 <_init-0x241>
 428:	2e 36 00 5f 5f       	cs add %bl,%ss:0x5f(%rdi)
 42d:	73 74                	jae    4a3 <_init-0x235>
 42f:	61                   	(bad)  
 430:	63 6b 5f             	movslq 0x5f(%rbx),%ebp
 433:	63 68 6b             	movslq 0x6b(%rax),%ebp
 436:	5f                   	pop    %rdi
 437:	66 61                	data16 (bad) 
 439:	69 6c 00 67 65 74 70 	imul   $0x69707465,0x67(%rax,%rax,1),%ebp
 440:	69 
 441:	64 00 70 72          	add    %dh,%fs:0x72(%rax)
 445:	69 6e 74 66 00 73 74 	imul   $0x74730066,0x74(%rsi),%ebp
 44c:	72 74                	jb     4c2 <_init-0x216>
 44e:	6f                   	outsl  %ds:(%rsi),(%dx)
 44f:	6b 00 73             	imul   $0x73,(%rax),%eax
 452:	74 72                	je     4c6 <_init-0x212>
 454:	74 6f                	je     4c5 <_init-0x213>
 456:	6c                   	insb   (%dx),%es:(%rdi)
 457:	00 72 65             	add    %dh,0x65(%rdx)
 45a:	61                   	(bad)  
 45b:	64 00 6d 61          	add    %ch,%fs:0x61(%rbp)
 45f:	6c                   	insb   (%dx),%es:(%rdi)
 460:	6c                   	insb   (%dx),%es:(%rdi)
 461:	6f                   	outsl  %ds:(%rsi),(%dx)
 462:	63 00                	movslq (%rax),%eax
 464:	69 6f 63 74 6c 00 6f 	imul   $0x6f006c74,0x63(%rdi),%ebp
 46b:	70 65                	jo     4d2 <_init-0x206>
 46d:	6e                   	outsb  %ds:(%rsi),(%dx)
 46e:	00 5f 5f             	add    %bl,0x5f(%rdi)
 471:	63 78 61             	movslq 0x61(%rax),%edi
 474:	5f                   	pop    %rdi
 475:	66 69 6e 61 6c 69    	imul   $0x696c,0x61(%rsi),%bp
 47b:	7a 65                	jp     4e2 <_init-0x1f6>
 47d:	00 5f 5f             	add    %bl,0x5f(%rdi)
 480:	6c                   	insb   (%dx),%es:(%rdi)
 481:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
 488:	72 74                	jb     4fe <_init-0x1da>
 48a:	5f                   	pop    %rdi
 48b:	6d                   	insl   (%dx),%es:(%rdi)
 48c:	61                   	(bad)  
 48d:	69 6e 00 47 4c 49 42 	imul   $0x42494c47,0x0(%rsi),%ebp
 494:	43 5f                	rex.XB pop %r15
 496:	32 2e                	xor    (%rsi),%ch
 498:	34 00                	xor    $0x0,%al
 49a:	47                   	rex.RXB
 49b:	4c                   	rex.WR
 49c:	49                   	rex.WB
 49d:	42                   	rex.X
 49e:	43 5f                	rex.XB pop %r15
 4a0:	32 2e                	xor    (%rsi),%ch
 4a2:	32 2e                	xor    (%rsi),%ch
 4a4:	35 00 5f 49 54       	xor    $0x54495f00,%eax
 4a9:	4d 5f                	rex.WRB pop %r15
 4ab:	64 65 72 65          	fs gs jb 514 <_init-0x1c4>
 4af:	67 69 73 74 65 72 54 	imul   $0x4d547265,0x74(%ebx),%esi
 4b6:	4d 
 4b7:	43 6c                	rex.XB insb (%dx),%es:(%rdi)
 4b9:	6f                   	outsl  %ds:(%rsi),(%dx)
 4ba:	6e                   	outsb  %ds:(%rsi),(%dx)
 4bb:	65 54                	gs push %rsp
 4bd:	61                   	(bad)  
 4be:	62                   	(bad)  
 4bf:	6c                   	insb   (%dx),%es:(%rdi)
 4c0:	65 00 5f 5f          	add    %bl,%gs:0x5f(%rdi)
 4c4:	67 6d                	insl   (%dx),%es:(%edi)
 4c6:	6f                   	outsl  %ds:(%rsi),(%dx)
 4c7:	6e                   	outsb  %ds:(%rsi),(%dx)
 4c8:	5f                   	pop    %rdi
 4c9:	73 74                	jae    53f <_init-0x199>
 4cb:	61                   	(bad)  
 4cc:	72 74                	jb     542 <_init-0x196>
 4ce:	5f                   	pop    %rdi
 4cf:	5f                   	pop    %rdi
 4d0:	00 5f 49             	add    %bl,0x49(%rdi)
 4d3:	54                   	push   %rsp
 4d4:	4d 5f                	rex.WRB pop %r15
 4d6:	72 65                	jb     53d <_init-0x19b>
 4d8:	67 69 73 74 65 72 54 	imul   $0x4d547265,0x74(%ebx),%esi
 4df:	4d 
 4e0:	43 6c                	rex.XB insb (%dx),%es:(%rdi)
 4e2:	6f                   	outsl  %ds:(%rsi),(%dx)
 4e3:	6e                   	outsb  %ds:(%rsi),(%dx)
 4e4:	65 54                	gs push %rsp
 4e6:	61                   	(bad)  
 4e7:	62                   	.byte 0x62
 4e8:	6c                   	insb   (%dx),%es:(%rdi)
 4e9:	65                   	gs
	...

Disassemblamento della sezione .gnu.version:

00000000000004ec <.gnu.version>:
 4ec:	00 00                	add    %al,(%rax)
 4ee:	00 00                	add    %al,(%rax)
 4f0:	02 00                	add    (%rax),%al
 4f2:	03 00                	add    (%rax),%eax
 4f4:	02 00                	add    (%rax),%al
 4f6:	02 00                	add    (%rax),%al
 4f8:	02 00                	add    (%rax),%al
 4fa:	02 00                	add    (%rax),%al
 4fc:	00 00                	add    %al,(%rax)
 4fe:	02 00                	add    (%rax),%al
 500:	02 00                	add    (%rax),%al
 502:	02 00                	add    (%rax),%al
 504:	02 00                	add    (%rax),%al
 506:	00 00                	add    %al,(%rax)
 508:	02 00                	add    (%rax),%al

Disassemblamento della sezione .gnu.version_r:

0000000000000510 <.gnu.version_r>:
 510:	01 00                	add    %eax,(%rax)
 512:	02 00                	add    (%rax),%al
 514:	01 00                	add    %eax,(%rax)
 516:	00 00                	add    %al,(%rax)
 518:	10 00                	adc    %al,(%rax)
 51a:	00 00                	add    %al,(%rax)
 51c:	00 00                	add    %al,(%rax)
 51e:	00 00                	add    %al,(%rax)
 520:	14 69                	adc    $0x69,%al
 522:	69 0d 00 00 03 00 70 	imul   $0x70,0x30000(%rip),%ecx        # 3052c <__FRAME_END__+0x2f6e8>
 529:	00 00 00 
 52c:	10 00                	adc    %al,(%rax)
 52e:	00 00                	add    %al,(%rax)
 530:	75 1a                	jne    54c <_init-0x18c>
 532:	69 09 00 00 02 00    	imul   $0x20000,(%rcx),%ecx
 538:	7a 00                	jp     53a <_init-0x19e>
 53a:	00 00                	add    %al,(%rax)
 53c:	00 00                	add    %al,(%rax)
	...

Disassemblamento della sezione .rela.dyn:

0000000000000540 <.rela.dyn>:
 540:	78 1d                	js     55f <_init-0x179>
 542:	20 00                	and    %al,(%rax)
 544:	00 00                	add    %al,(%rax)
 546:	00 00                	add    %al,(%rax)
 548:	08 00                	or     %al,(%rax)
 54a:	00 00                	add    %al,(%rax)
 54c:	00 00                	add    %al,(%rax)
 54e:	00 00                	add    %al,(%rax)
 550:	a0 08 00 00 00 00 00 	movabs 0x8000000000000008,%al
 557:	00 80 
 559:	1d 20 00 00 00       	sbb    $0x20,%eax
 55e:	00 00                	add    %al,(%rax)
 560:	08 00                	or     %al,(%rax)
 562:	00 00                	add    %al,(%rax)
 564:	00 00                	add    %al,(%rax)
 566:	00 00                	add    %al,(%rax)
 568:	60                   	(bad)  
 569:	08 00                	or     %al,(%rax)
 56b:	00 00                	add    %al,(%rax)
 56d:	00 00                	add    %al,(%rax)
 56f:	00 08                	add    %cl,(%rax)
 571:	20 20                	and    %ah,(%rax)
 573:	00 00                	add    %al,(%rax)
 575:	00 00                	add    %al,(%rax)
 577:	00 08                	add    %cl,(%rax)
 579:	00 00                	add    %al,(%rax)
 57b:	00 00                	add    %al,(%rax)
 57d:	00 00                	add    %al,(%rax)
 57f:	00 08                	add    %cl,(%rax)
 581:	20 20                	and    %ah,(%rax)
 583:	00 00                	add    %al,(%rax)
 585:	00 00                	add    %al,(%rax)
 587:	00 d8                	add    %bl,%al
 589:	1f                   	(bad)  
 58a:	20 00                	and    %al,(%rax)
 58c:	00 00                	add    %al,(%rax)
 58e:	00 00                	add    %al,(%rax)
 590:	06                   	(bad)  
 591:	00 00                	add    %al,(%rax)
 593:	00 01                	add    %al,(%rcx)
	...
 59d:	00 00                	add    %al,(%rax)
 59f:	00 e0                	add    %ah,%al
 5a1:	1f                   	(bad)  
 5a2:	20 00                	and    %al,(%rax)
 5a4:	00 00                	add    %al,(%rax)
 5a6:	00 00                	add    %al,(%rax)
 5a8:	06                   	(bad)  
 5a9:	00 00                	add    %al,(%rax)
 5ab:	00 07                	add    %al,(%rdi)
	...
 5b5:	00 00                	add    %al,(%rax)
 5b7:	00 e8                	add    %ch,%al
 5b9:	1f                   	(bad)  
 5ba:	20 00                	and    %al,(%rax)
 5bc:	00 00                	add    %al,(%rax)
 5be:	00 00                	add    %al,(%rax)
 5c0:	06                   	(bad)  
 5c1:	00 00                	add    %al,(%rax)
 5c3:	00 08                	add    %cl,(%rax)
	...
 5cd:	00 00                	add    %al,(%rax)
 5cf:	00 f0                	add    %dh,%al
 5d1:	1f                   	(bad)  
 5d2:	20 00                	and    %al,(%rax)
 5d4:	00 00                	add    %al,(%rax)
 5d6:	00 00                	add    %al,(%rax)
 5d8:	06                   	(bad)  
 5d9:	00 00                	add    %al,(%rax)
 5db:	00 0d 00 00 00 00    	add    %cl,0x0(%rip)        # 5e1 <_init-0xf7>
 5e1:	00 00                	add    %al,(%rax)
 5e3:	00 00                	add    %al,(%rax)
 5e5:	00 00                	add    %al,(%rax)
 5e7:	00 f8                	add    %bh,%al
 5e9:	1f                   	(bad)  
 5ea:	20 00                	and    %al,(%rax)
 5ec:	00 00                	add    %al,(%rax)
 5ee:	00 00                	add    %al,(%rax)
 5f0:	06                   	(bad)  
 5f1:	00 00                	add    %al,(%rax)
 5f3:	00 0e                	add    %cl,(%rsi)
	...

Disassemblamento della sezione .rela.plt:

0000000000000600 <.rela.plt>:
 600:	90                   	nop
 601:	1f                   	(bad)  
 602:	20 00                	and    %al,(%rax)
 604:	00 00                	add    %al,(%rax)
 606:	00 00                	add    %al,(%rax)
 608:	07                   	(bad)  
 609:	00 00                	add    %al,(%rax)
 60b:	00 02                	add    %al,(%rdx)
	...
 615:	00 00                	add    %al,(%rax)
 617:	00 98 1f 20 00 00    	add    %bl,0x201f(%rax)
 61d:	00 00                	add    %al,(%rax)
 61f:	00 07                	add    %al,(%rdi)
 621:	00 00                	add    %al,(%rax)
 623:	00 03                	add    %al,(%rbx)
	...
 62d:	00 00                	add    %al,(%rax)
 62f:	00 a0 1f 20 00 00    	add    %ah,0x201f(%rax)
 635:	00 00                	add    %al,(%rax)
 637:	00 07                	add    %al,(%rdi)
 639:	00 00                	add    %al,(%rax)
 63b:	00 04 00             	add    %al,(%rax,%rax,1)
	...
 646:	00 00                	add    %al,(%rax)
 648:	a8 1f                	test   $0x1f,%al
 64a:	20 00                	and    %al,(%rax)
 64c:	00 00                	add    %al,(%rax)
 64e:	00 00                	add    %al,(%rax)
 650:	07                   	(bad)  
 651:	00 00                	add    %al,(%rax)
 653:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 659 <_init-0x7f>
 659:	00 00                	add    %al,(%rax)
 65b:	00 00                	add    %al,(%rax)
 65d:	00 00                	add    %al,(%rax)
 65f:	00 b0 1f 20 00 00    	add    %dh,0x201f(%rax)
 665:	00 00                	add    %al,(%rax)
 667:	00 07                	add    %al,(%rdi)
 669:	00 00                	add    %al,(%rax)
 66b:	00 06                	add    %al,(%rsi)
	...
 675:	00 00                	add    %al,(%rax)
 677:	00 b8 1f 20 00 00    	add    %bh,0x201f(%rax)
 67d:	00 00                	add    %al,(%rax)
 67f:	00 07                	add    %al,(%rdi)
 681:	00 00                	add    %al,(%rax)
 683:	00 09                	add    %cl,(%rcx)
	...
 68d:	00 00                	add    %al,(%rax)
 68f:	00 c0                	add    %al,%al
 691:	1f                   	(bad)  
 692:	20 00                	and    %al,(%rax)
 694:	00 00                	add    %al,(%rax)
 696:	00 00                	add    %al,(%rax)
 698:	07                   	(bad)  
 699:	00 00                	add    %al,(%rax)
 69b:	00 0a                	add    %cl,(%rdx)
	...
 6a5:	00 00                	add    %al,(%rax)
 6a7:	00 c8                	add    %cl,%al
 6a9:	1f                   	(bad)  
 6aa:	20 00                	and    %al,(%rax)
 6ac:	00 00                	add    %al,(%rax)
 6ae:	00 00                	add    %al,(%rax)
 6b0:	07                   	(bad)  
 6b1:	00 00                	add    %al,(%rax)
 6b3:	00 0b                	add    %cl,(%rbx)
	...
 6bd:	00 00                	add    %al,(%rax)
 6bf:	00 d0                	add    %dl,%al
 6c1:	1f                   	(bad)  
 6c2:	20 00                	and    %al,(%rax)
 6c4:	00 00                	add    %al,(%rax)
 6c6:	00 00                	add    %al,(%rax)
 6c8:	07                   	(bad)  
 6c9:	00 00                	add    %al,(%rax)
 6cb:	00 0c 00             	add    %cl,(%rax,%rax,1)
	...

Disassemblamento della sezione .init:

00000000000006d8 <_init>:
 6d8:	48 83 ec 08          	sub    $0x8,%rsp
 6dc:	48 8b 05 05 19 20 00 	mov    0x201905(%rip),%rax        # 201fe8 <__gmon_start__>
 6e3:	48 85 c0             	test   %rax,%rax
 6e6:	74 02                	je     6ea <_init+0x12>
 6e8:	ff d0                	callq  *%rax
 6ea:	48 83 c4 08          	add    $0x8,%rsp
 6ee:	c3                   	retq   

Disassemblamento della sezione .plt:

00000000000006f0 <.plt>:
 6f0:	ff 35 8a 18 20 00    	pushq  0x20188a(%rip)        # 201f80 <_GLOBAL_OFFSET_TABLE_+0x8>
 6f6:	ff 25 8c 18 20 00    	jmpq   *0x20188c(%rip)        # 201f88 <_GLOBAL_OFFSET_TABLE_+0x10>
 6fc:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000000700 <getpid@plt>:
 700:	ff 25 8a 18 20 00    	jmpq   *0x20188a(%rip)        # 201f90 <getpid@GLIBC_2.2.5>
 706:	68 00 00 00 00       	pushq  $0x0
 70b:	e9 e0 ff ff ff       	jmpq   6f0 <.plt>

0000000000000710 <__stack_chk_fail@plt>:
 710:	ff 25 82 18 20 00    	jmpq   *0x201882(%rip)        # 201f98 <__stack_chk_fail@GLIBC_2.4>
 716:	68 01 00 00 00       	pushq  $0x1
 71b:	e9 d0 ff ff ff       	jmpq   6f0 <.plt>

0000000000000720 <printf@plt>:
 720:	ff 25 7a 18 20 00    	jmpq   *0x20187a(%rip)        # 201fa0 <printf@GLIBC_2.2.5>
 726:	68 02 00 00 00       	pushq  $0x2
 72b:	e9 c0 ff ff ff       	jmpq   6f0 <.plt>

0000000000000730 <ioctl@plt>:
 730:	ff 25 72 18 20 00    	jmpq   *0x201872(%rip)        # 201fa8 <ioctl@GLIBC_2.2.5>
 736:	68 03 00 00 00       	pushq  $0x3
 73b:	e9 b0 ff ff ff       	jmpq   6f0 <.plt>

0000000000000740 <read@plt>:
 740:	ff 25 6a 18 20 00    	jmpq   *0x20186a(%rip)        # 201fb0 <read@GLIBC_2.2.5>
 746:	68 04 00 00 00       	pushq  $0x4
 74b:	e9 a0 ff ff ff       	jmpq   6f0 <.plt>

0000000000000750 <strtol@plt>:
 750:	ff 25 62 18 20 00    	jmpq   *0x201862(%rip)        # 201fb8 <strtol@GLIBC_2.2.5>
 756:	68 05 00 00 00       	pushq  $0x5
 75b:	e9 90 ff ff ff       	jmpq   6f0 <.plt>

0000000000000760 <malloc@plt>:
 760:	ff 25 5a 18 20 00    	jmpq   *0x20185a(%rip)        # 201fc0 <malloc@GLIBC_2.2.5>
 766:	68 06 00 00 00       	pushq  $0x6
 76b:	e9 80 ff ff ff       	jmpq   6f0 <.plt>

0000000000000770 <open@plt>:
 770:	ff 25 52 18 20 00    	jmpq   *0x201852(%rip)        # 201fc8 <open@GLIBC_2.2.5>
 776:	68 07 00 00 00       	pushq  $0x7
 77b:	e9 70 ff ff ff       	jmpq   6f0 <.plt>

0000000000000780 <strtok@plt>:
 780:	ff 25 4a 18 20 00    	jmpq   *0x20184a(%rip)        # 201fd0 <strtok@GLIBC_2.2.5>
 786:	68 08 00 00 00       	pushq  $0x8
 78b:	e9 60 ff ff ff       	jmpq   6f0 <.plt>

Disassemblamento della sezione .plt.got:

0000000000000790 <__cxa_finalize@plt>:
 790:	ff 25 62 18 20 00    	jmpq   *0x201862(%rip)        # 201ff8 <__cxa_finalize@GLIBC_2.2.5>
 796:	66 90                	xchg   %ax,%ax

Disassemblamento della sezione .text:

00000000000007a0 <_start>:
 7a0:	31 ed                	xor    %ebp,%ebp
 7a2:	49 89 d1             	mov    %rdx,%r9
 7a5:	5e                   	pop    %rsi
 7a6:	48 89 e2             	mov    %rsp,%rdx
 7a9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
 7ad:	50                   	push   %rax
 7ae:	54                   	push   %rsp
 7af:	4c 8d 05 aa 04 00 00 	lea    0x4aa(%rip),%r8        # c60 <__libc_csu_fini>
 7b6:	48 8d 0d 33 04 00 00 	lea    0x433(%rip),%rcx        # bf0 <__libc_csu_init>
 7bd:	48 8d 3d 1c 01 00 00 	lea    0x11c(%rip),%rdi        # 8e0 <main>
 7c4:	ff 15 16 18 20 00    	callq  *0x201816(%rip)        # 201fe0 <__libc_start_main@GLIBC_2.2.5>
 7ca:	f4                   	hlt    
 7cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000007d0 <deregister_tm_clones>:
 7d0:	48 8d 3d 39 18 20 00 	lea    0x201839(%rip),%rdi        # 202010 <__TMC_END__>
 7d7:	55                   	push   %rbp
 7d8:	48 8d 05 31 18 20 00 	lea    0x201831(%rip),%rax        # 202010 <__TMC_END__>
 7df:	48 39 f8             	cmp    %rdi,%rax
 7e2:	48 89 e5             	mov    %rsp,%rbp
 7e5:	74 19                	je     800 <deregister_tm_clones+0x30>
 7e7:	48 8b 05 ea 17 20 00 	mov    0x2017ea(%rip),%rax        # 201fd8 <_ITM_deregisterTMCloneTable>
 7ee:	48 85 c0             	test   %rax,%rax
 7f1:	74 0d                	je     800 <deregister_tm_clones+0x30>
 7f3:	5d                   	pop    %rbp
 7f4:	ff e0                	jmpq   *%rax
 7f6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 7fd:	00 00 00 
 800:	5d                   	pop    %rbp
 801:	c3                   	retq   
 802:	0f 1f 40 00          	nopl   0x0(%rax)
 806:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 80d:	00 00 00 

0000000000000810 <register_tm_clones>:
 810:	48 8d 3d f9 17 20 00 	lea    0x2017f9(%rip),%rdi        # 202010 <__TMC_END__>
 817:	48 8d 35 f2 17 20 00 	lea    0x2017f2(%rip),%rsi        # 202010 <__TMC_END__>
 81e:	55                   	push   %rbp
 81f:	48 29 fe             	sub    %rdi,%rsi
 822:	48 89 e5             	mov    %rsp,%rbp
 825:	48 c1 fe 03          	sar    $0x3,%rsi
 829:	48 89 f0             	mov    %rsi,%rax
 82c:	48 c1 e8 3f          	shr    $0x3f,%rax
 830:	48 01 c6             	add    %rax,%rsi
 833:	48 d1 fe             	sar    %rsi
 836:	74 18                	je     850 <register_tm_clones+0x40>
 838:	48 8b 05 b1 17 20 00 	mov    0x2017b1(%rip),%rax        # 201ff0 <_ITM_registerTMCloneTable>
 83f:	48 85 c0             	test   %rax,%rax
 842:	74 0c                	je     850 <register_tm_clones+0x40>
 844:	5d                   	pop    %rbp
 845:	ff e0                	jmpq   *%rax
 847:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 84e:	00 00 
 850:	5d                   	pop    %rbp
 851:	c3                   	retq   
 852:	0f 1f 40 00          	nopl   0x0(%rax)
 856:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 85d:	00 00 00 

0000000000000860 <__do_global_dtors_aux>:
 860:	80 3d a9 17 20 00 00 	cmpb   $0x0,0x2017a9(%rip)        # 202010 <__TMC_END__>
 867:	75 2f                	jne    898 <__do_global_dtors_aux+0x38>
 869:	48 83 3d 87 17 20 00 	cmpq   $0x0,0x201787(%rip)        # 201ff8 <__cxa_finalize@GLIBC_2.2.5>
 870:	00 
 871:	55                   	push   %rbp
 872:	48 89 e5             	mov    %rsp,%rbp
 875:	74 0c                	je     883 <__do_global_dtors_aux+0x23>
 877:	48 8b 3d 8a 17 20 00 	mov    0x20178a(%rip),%rdi        # 202008 <__dso_handle>
 87e:	e8 0d ff ff ff       	callq  790 <__cxa_finalize@plt>
 883:	e8 48 ff ff ff       	callq  7d0 <deregister_tm_clones>
 888:	c6 05 81 17 20 00 01 	movb   $0x1,0x201781(%rip)        # 202010 <__TMC_END__>
 88f:	5d                   	pop    %rbp
 890:	c3                   	retq   
 891:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 898:	f3 c3                	repz retq 
 89a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000008a0 <frame_dummy>:
 8a0:	55                   	push   %rbp
 8a1:	48 89 e5             	mov    %rsp,%rbp
 8a4:	5d                   	pop    %rbp
 8a5:	e9 66 ff ff ff       	jmpq   810 <register_tm_clones>

00000000000008aa <myfunction>:
 8aa:	55                   	push   %rbp
 8ab:	48 89 e5             	mov    %rsp,%rbp
 8ae:	48 83 ec 20          	sub    $0x20,%rsp
 8b2:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
 8b6:	48 c7 45 f8 00 00 00 	movq   $0x0,-0x8(%rbp)
 8bd:	00 
 8be:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 8c2:	48 8d 50 01          	lea    0x1(%rax),%rdx
 8c6:	48 89 55 f8          	mov    %rdx,-0x8(%rbp)
 8ca:	48 89 c6             	mov    %rax,%rsi
 8cd:	48 8d 3d a4 03 00 00 	lea    0x3a4(%rip),%rdi        # c78 <_IO_stdin_used+0x8>
 8d4:	b8 00 00 00 00       	mov    $0x0,%eax
 8d9:	e8 42 fe ff ff       	callq  720 <printf@plt>
 8de:	eb de                	jmp    8be <myfunction+0x14>

00000000000008e0 <main>:
 8e0:	55                   	push   %rbp
 8e1:	48 89 e5             	mov    %rsp,%rbp
 8e4:	53                   	push   %rbx
 8e5:	48 81 ec c8 01 00 00 	sub    $0x1c8,%rsp
 8ec:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
 8f3:	00 00 
 8f5:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
 8f9:	31 c0                	xor    %eax,%eax
 8fb:	be 00 00 00 00       	mov    $0x0,%esi
 900:	48 8d 3d 76 03 00 00 	lea    0x376(%rip),%rdi        # c7d <_IO_stdin_used+0xd>
 907:	b8 00 00 00 00       	mov    $0x0,%eax
 90c:	e8 5f fe ff ff       	callq  770 <open@plt>
 911:	89 85 38 fe ff ff    	mov    %eax,-0x1c8(%rbp)
 917:	48 8d 8d e0 fe ff ff 	lea    -0x120(%rbp),%rcx
 91e:	8b 85 38 fe ff ff    	mov    -0x1c8(%rbp),%eax
 924:	ba 00 01 00 00       	mov    $0x100,%edx
 929:	48 89 ce             	mov    %rcx,%rsi
 92c:	89 c7                	mov    %eax,%edi
 92e:	e8 0d fe ff ff       	callq  740 <read@plt>
 933:	48 89 85 58 fe ff ff 	mov    %rax,-0x1a8(%rbp)
 93a:	66 c7 85 de fe ff ff 	movw   $0xa,-0x122(%rbp)
 941:	0a 00 
 943:	48 8d 95 de fe ff ff 	lea    -0x122(%rbp),%rdx
 94a:	48 8d 85 e0 fe ff ff 	lea    -0x120(%rbp),%rax
 951:	48 89 d6             	mov    %rdx,%rsi
 954:	48 89 c7             	mov    %rax,%rdi
 957:	e8 24 fe ff ff       	callq  780 <strtok@plt>
 95c:	48 89 85 50 fe ff ff 	mov    %rax,-0x1b0(%rbp)
 963:	48 c7 85 a0 fe ff ff 	movq   $0x0,-0x160(%rbp)
 96a:	00 00 00 00 
 96e:	48 c7 85 a8 fe ff ff 	movq   $0x0,-0x158(%rbp)
 975:	00 00 00 00 
 979:	48 c7 85 b0 fe ff ff 	movq   $0x0,-0x150(%rbp)
 980:	00 00 00 00 
 984:	48 c7 85 b8 fe ff ff 	movq   $0x0,-0x148(%rbp)
 98b:	00 00 00 00 
 98f:	48 c7 85 c0 fe ff ff 	movq   $0x0,-0x140(%rbp)
 996:	00 00 00 00 
 99a:	48 c7 85 c8 fe ff ff 	movq   $0x0,-0x138(%rbp)
 9a1:	00 00 00 00 
 9a5:	48 c7 85 d0 fe ff ff 	movq   $0x0,-0x130(%rbp)
 9ac:	00 00 00 00 
 9b0:	c7 85 34 fe ff ff 00 	movl   $0x0,-0x1cc(%rbp)
 9b7:	00 00 00 
 9ba:	eb 53                	jmp    a0f <main+0x12f>
 9bc:	48 8d 8d 40 fe ff ff 	lea    -0x1c0(%rbp),%rcx
 9c3:	48 8b 85 50 fe ff ff 	mov    -0x1b0(%rbp),%rax
 9ca:	ba 0a 00 00 00       	mov    $0xa,%edx
 9cf:	48 89 ce             	mov    %rcx,%rsi
 9d2:	48 89 c7             	mov    %rax,%rdi
 9d5:	e8 76 fd ff ff       	callq  750 <strtol@plt>
 9da:	48 89 c2             	mov    %rax,%rdx
 9dd:	8b 85 34 fe ff ff    	mov    -0x1cc(%rbp),%eax
 9e3:	48 98                	cltq   
 9e5:	48 89 94 c5 a0 fe ff 	mov    %rdx,-0x160(%rbp,%rax,8)
 9ec:	ff 
 9ed:	48 8d 85 de fe ff ff 	lea    -0x122(%rbp),%rax
 9f4:	48 89 c6             	mov    %rax,%rsi
 9f7:	bf 00 00 00 00       	mov    $0x0,%edi
 9fc:	e8 7f fd ff ff       	callq  780 <strtok@plt>
 a01:	48 89 85 50 fe ff ff 	mov    %rax,-0x1b0(%rbp)
 a08:	83 85 34 fe ff ff 01 	addl   $0x1,-0x1cc(%rbp)
 a0f:	48 83 bd 50 fe ff ff 	cmpq   $0x0,-0x1b0(%rbp)
 a16:	00 
 a17:	75 a3                	jne    9bc <main+0xdc>
 a19:	c7 85 34 fe ff ff 00 	movl   $0x0,-0x1cc(%rbp)
 a20:	00 00 00 
 a23:	eb 2b                	jmp    a50 <main+0x170>
 a25:	8b 85 34 fe ff ff    	mov    -0x1cc(%rbp),%eax
 a2b:	48 98                	cltq   
 a2d:	48 8b 84 c5 a0 fe ff 	mov    -0x160(%rbp,%rax,8),%rax
 a34:	ff 
 a35:	48 89 c6             	mov    %rax,%rsi
 a38:	48 8d 3d 39 02 00 00 	lea    0x239(%rip),%rdi        # c78 <_IO_stdin_used+0x8>
 a3f:	b8 00 00 00 00       	mov    $0x0,%eax
 a44:	e8 d7 fc ff ff       	callq  720 <printf@plt>
 a49:	83 85 34 fe ff ff 01 	addl   $0x1,-0x1cc(%rbp)
 a50:	83 bd 34 fe ff ff 06 	cmpl   $0x6,-0x1cc(%rbp)
 a57:	7e cc                	jle    a25 <main+0x145>
 a59:	48 c7 85 48 fe ff ff 	movq   $0x1,-0x1b8(%rbp)
 a60:	01 00 00 00 
 a64:	48 c7 85 60 fe ff ff 	movq   $0x0,-0x1a0(%rbp)
 a6b:	00 00 00 00 
 a6f:	48 c7 85 68 fe ff ff 	movq   $0x0,-0x198(%rbp)
 a76:	00 00 00 00 
 a7a:	48 c7 85 70 fe ff ff 	movq   $0x0,-0x190(%rbp)
 a81:	00 00 00 00 
 a85:	48 c7 85 78 fe ff ff 	movq   $0x0,-0x188(%rbp)
 a8c:	00 00 00 00 
 a90:	48 c7 85 80 fe ff ff 	movq   $0x0,-0x180(%rbp)
 a97:	00 00 00 00 
 a9b:	48 c7 85 88 fe ff ff 	movq   $0x0,-0x178(%rbp)
 aa2:	00 00 00 00 
 aa6:	48 c7 85 90 fe ff ff 	movq   $0x0,-0x170(%rbp)
 aad:	00 00 00 00 
 ab1:	48 c7 85 98 fe ff ff 	movq   $0x0,-0x168(%rbp)
 ab8:	00 00 00 00 
 abc:	48 c7 85 68 fe ff ff 	movq   $0x1,-0x198(%rbp)
 ac3:	01 00 00 00 
 ac7:	48 8d 05 dc fd ff ff 	lea    -0x224(%rip),%rax        # 8aa <myfunction>
 ace:	48 89 85 70 fe ff ff 	mov    %rax,-0x190(%rbp)
 ad5:	48 8d 85 48 fe ff ff 	lea    -0x1b8(%rbp),%rax
 adc:	48 89 85 78 fe ff ff 	mov    %rax,-0x188(%rbp)
 ae3:	48 8b 85 a0 fe ff ff 	mov    -0x160(%rbp),%rax
 aea:	48 89 c1             	mov    %rax,%rcx
 aed:	8b 85 38 fe ff ff    	mov    -0x1c8(%rbp),%eax
 af3:	ba 00 00 00 00       	mov    $0x0,%edx
 af8:	48 89 ce             	mov    %rcx,%rsi
 afb:	89 c7                	mov    %eax,%edi
 afd:	b8 00 00 00 00       	mov    $0x0,%eax
 b02:	e8 29 fc ff ff       	callq  730 <ioctl@plt>
 b07:	48 98                	cltq   
 b09:	48 89 85 58 fe ff ff 	mov    %rax,-0x1a8(%rbp)
 b10:	bf 00 20 00 00       	mov    $0x2000,%edi
 b15:	e8 46 fc ff ff       	callq  760 <malloc@plt>
 b1a:	48 89 85 60 fe ff ff 	mov    %rax,-0x1a0(%rbp)
 b21:	48 8b 85 60 fe ff ff 	mov    -0x1a0(%rbp),%rax
 b28:	48 89 c6             	mov    %rax,%rsi
 b2b:	48 8d 3d 57 01 00 00 	lea    0x157(%rip),%rdi        # c89 <_IO_stdin_used+0x19>
 b32:	b8 00 00 00 00       	mov    $0x0,%eax
 b37:	e8 e4 fb ff ff       	callq  720 <printf@plt>
 b3c:	48 8b 85 a8 fe ff ff 	mov    -0x158(%rbp),%rax
 b43:	48 89 c1             	mov    %rax,%rcx
 b46:	48 8d 95 60 fe ff ff 	lea    -0x1a0(%rbp),%rdx
 b4d:	8b 85 38 fe ff ff    	mov    -0x1c8(%rbp),%eax
 b53:	48 89 ce             	mov    %rcx,%rsi
 b56:	89 c7                	mov    %eax,%edi
 b58:	b8 00 00 00 00       	mov    $0x0,%eax
 b5d:	e8 ce fb ff ff       	callq  730 <ioctl@plt>
 b62:	89 85 3c fe ff ff    	mov    %eax,-0x1c4(%rbp)
 b68:	8b 85 3c fe ff ff    	mov    -0x1c4(%rbp),%eax
 b6e:	89 85 80 fe ff ff    	mov    %eax,-0x180(%rbp)
 b74:	48 8d 1d 2f fd ff ff 	lea    -0x2d1(%rip),%rbx        # 8aa <myfunction>
 b7b:	e8 80 fb ff ff       	callq  700 <getpid@plt>
 b80:	89 c2                	mov    %eax,%edx
 b82:	8b 85 3c fe ff ff    	mov    -0x1c4(%rbp),%eax
 b88:	48 89 d9             	mov    %rbx,%rcx
 b8b:	89 c6                	mov    %eax,%esi
 b8d:	48 8d 3d 0c 01 00 00 	lea    0x10c(%rip),%rdi        # ca0 <_IO_stdin_used+0x30>
 b94:	b8 00 00 00 00       	mov    $0x0,%eax
 b99:	e8 82 fb ff ff       	callq  720 <printf@plt>
 b9e:	48 8b 85 b0 fe ff ff 	mov    -0x150(%rbp),%rax
 ba5:	48 89 c1             	mov    %rax,%rcx
 ba8:	48 8d 95 60 fe ff ff 	lea    -0x1a0(%rbp),%rdx
 baf:	8b 85 38 fe ff ff    	mov    -0x1c8(%rbp),%eax
 bb5:	48 89 ce             	mov    %rcx,%rsi
 bb8:	89 c7                	mov    %eax,%edi
 bba:	b8 00 00 00 00       	mov    $0x0,%eax
 bbf:	e8 6c fb ff ff       	callq  730 <ioctl@plt>
 bc4:	48 98                	cltq   
 bc6:	48 89 85 58 fe ff ff 	mov    %rax,-0x1a8(%rbp)
 bcd:	b8 00 00 00 00       	mov    $0x0,%eax
 bd2:	48 8b 5d e8          	mov    -0x18(%rbp),%rbx
 bd6:	64 48 33 1c 25 28 00 	xor    %fs:0x28,%rbx
 bdd:	00 00 
 bdf:	74 05                	je     be6 <main+0x306>
 be1:	e8 2a fb ff ff       	callq  710 <__stack_chk_fail@plt>
 be6:	48 81 c4 c8 01 00 00 	add    $0x1c8,%rsp
 bed:	5b                   	pop    %rbx
 bee:	5d                   	pop    %rbp
 bef:	c3                   	retq   

0000000000000bf0 <__libc_csu_init>:
 bf0:	41 57                	push   %r15
 bf2:	41 56                	push   %r14
 bf4:	49 89 d7             	mov    %rdx,%r15
 bf7:	41 55                	push   %r13
 bf9:	41 54                	push   %r12
 bfb:	4c 8d 25 76 11 20 00 	lea    0x201176(%rip),%r12        # 201d78 <__frame_dummy_init_array_entry>
 c02:	55                   	push   %rbp
 c03:	48 8d 2d 76 11 20 00 	lea    0x201176(%rip),%rbp        # 201d80 <__init_array_end>
 c0a:	53                   	push   %rbx
 c0b:	41 89 fd             	mov    %edi,%r13d
 c0e:	49 89 f6             	mov    %rsi,%r14
 c11:	4c 29 e5             	sub    %r12,%rbp
 c14:	48 83 ec 08          	sub    $0x8,%rsp
 c18:	48 c1 fd 03          	sar    $0x3,%rbp
 c1c:	e8 b7 fa ff ff       	callq  6d8 <_init>
 c21:	48 85 ed             	test   %rbp,%rbp
 c24:	74 20                	je     c46 <__libc_csu_init+0x56>
 c26:	31 db                	xor    %ebx,%ebx
 c28:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
 c2f:	00 
 c30:	4c 89 fa             	mov    %r15,%rdx
 c33:	4c 89 f6             	mov    %r14,%rsi
 c36:	44 89 ef             	mov    %r13d,%edi
 c39:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
 c3d:	48 83 c3 01          	add    $0x1,%rbx
 c41:	48 39 dd             	cmp    %rbx,%rbp
 c44:	75 ea                	jne    c30 <__libc_csu_init+0x40>
 c46:	48 83 c4 08          	add    $0x8,%rsp
 c4a:	5b                   	pop    %rbx
 c4b:	5d                   	pop    %rbp
 c4c:	41 5c                	pop    %r12
 c4e:	41 5d                	pop    %r13
 c50:	41 5e                	pop    %r14
 c52:	41 5f                	pop    %r15
 c54:	c3                   	retq   
 c55:	90                   	nop
 c56:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 c5d:	00 00 00 

0000000000000c60 <__libc_csu_fini>:
 c60:	f3 c3                	repz retq 

Disassemblamento della sezione .fini:

0000000000000c64 <_fini>:
 c64:	48 83 ec 08          	sub    $0x8,%rsp
 c68:	48 83 c4 08          	add    $0x8,%rsp
 c6c:	c3                   	retq   

Disassemblamento della sezione .rodata:

0000000000000c70 <_IO_stdin_used>:
 c70:	01 00                	add    %eax,(%rax)
 c72:	02 00                	add    (%rax),%al
 c74:	00 00                	add    %al,(%rax)
 c76:	00 00                	add    %al,(%rax)
 c78:	25 6c 64 0a 00       	and    $0xa646c,%eax
 c7d:	2f                   	(bad)  
 c7e:	64 65 76 2f          	fs gs jbe cb1 <_IO_stdin_used+0x41>
 c82:	66 69 62 65 72 73    	imul   $0x7372,0x65(%rdx),%sp
 c88:	00 73 74             	add    %dh,0x74(%rbx)
 c8b:	61                   	(bad)  
 c8c:	63 6b 5f             	movslq 0x5f(%rbx),%ebp
 c8f:	70 6f                	jo     d00 <__GNU_EH_FRAME_HDR+0x24>
 c91:	69 6e 74 65 72 20 69 	imul   $0x69207265,0x74(%rsi),%ebp
 c98:	73 20                	jae    cba <_IO_stdin_used+0x4a>
 c9a:	25 6c 75 0a 00       	and    $0xa756c,%eax
 c9f:	00 72 65             	add    %dh,0x65(%rdx)
 ca2:	74 20                	je     cc4 <_IO_stdin_used+0x54>
 ca4:	76 61                	jbe    d07 <__GNU_EH_FRAME_HDR+0x2b>
 ca6:	6c                   	insb   (%dx),%es:(%rdi)
 ca7:	75 65                	jne    d0e <__GNU_EH_FRAME_HDR+0x32>
 ca9:	20 69 73             	and    %ch,0x73(%rcx)
 cac:	20 25 64 2c 20 50    	and    %ah,0x50202c64(%rip)        # 50203916 <_end+0x500018fe>
 cb2:	49                   	rex.WB
 cb3:	44 20 69 73          	and    %r13b,0x73(%rcx)
 cb7:	20 25 64 0a 20 6d    	and    %ah,0x6d200a64(%rip)        # 6d201721 <_end+0x6cfff709>
 cbd:	79 66                	jns    d25 <__GNU_EH_FRAME_HDR+0x49>
 cbf:	75 6e                	jne    d2f <__GNU_EH_FRAME_HDR+0x53>
 cc1:	63 74 69 6f          	movslq 0x6f(%rcx,%rbp,2),%esi
 cc5:	6e                   	outsb  %ds:(%rsi),(%dx)
 cc6:	20 69 73             	and    %ch,0x73(%rcx)
 cc9:	20 69 6e             	and    %ch,0x6e(%rcx)
 ccc:	20 61 64             	and    %ah,0x64(%rcx)
 ccf:	64 72 65             	fs jb  d37 <__GNU_EH_FRAME_HDR+0x5b>
 cd2:	73 73                	jae    d47 <__GNU_EH_FRAME_HDR+0x6b>
 cd4:	20 25 6c 75 0a 00    	and    %ah,0xa756c(%rip)        # a8246 <__FRAME_END__+0xa7402>

Disassemblamento della sezione .eh_frame_hdr:

0000000000000cdc <__GNU_EH_FRAME_HDR>:
 cdc:	01 1b                	add    %ebx,(%rbx)
 cde:	03 3b                	add    (%rbx),%edi
 ce0:	40 00 00             	add    %al,(%rax)
 ce3:	00 07                	add    %al,(%rdi)
 ce5:	00 00                	add    %al,(%rax)
 ce7:	00 14 fa             	add    %dl,(%rdx,%rdi,8)
 cea:	ff                   	(bad)  
 ceb:	ff 8c 00 00 00 b4 fa 	decl   -0x54c0000(%rax,%rax,1)
 cf2:	ff                   	(bad)  
 cf3:	ff b4 00 00 00 c4 fa 	pushq  -0x53c0000(%rax,%rax,1)
 cfa:	ff                   	(bad)  
 cfb:	ff 5c 00 00          	lcall  *0x0(%rax,%rax,1)
 cff:	00 ce                	add    %cl,%dh
 d01:	fb                   	sti    
 d02:	ff                   	(bad)  
 d03:	ff cc                	dec    %esp
 d05:	00 00                	add    %al,(%rax)
 d07:	00 04 fc             	add    %al,(%rsp,%rdi,8)
 d0a:	ff                   	(bad)  
 d0b:	ff                   	(bad)  
 d0c:	e8 00 00 00 14       	callq  14000d11 <_end+0x13dfecf9>
 d11:	ff                   	(bad)  
 d12:	ff                   	(bad)  
 d13:	ff 0c 01             	decl   (%rcx,%rax,1)
 d16:	00 00                	add    %al,(%rax)
 d18:	84 ff                	test   %bh,%bh
 d1a:	ff                   	(bad)  
 d1b:	ff 54 01 00          	callq  *0x0(%rcx,%rax,1)
	...

Disassemblamento della sezione .eh_frame:

0000000000000d20 <__FRAME_END__-0x124>:
 d20:	14 00                	adc    $0x0,%al
 d22:	00 00                	add    %al,(%rax)
 d24:	00 00                	add    %al,(%rax)
 d26:	00 00                	add    %al,(%rax)
 d28:	01 7a 52             	add    %edi,0x52(%rdx)
 d2b:	00 01                	add    %al,(%rcx)
 d2d:	78 10                	js     d3f <__GNU_EH_FRAME_HDR+0x63>
 d2f:	01 1b                	add    %ebx,(%rbx)
 d31:	0c 07                	or     $0x7,%al
 d33:	08 90 01 07 10 14    	or     %dl,0x14100701(%rax)
 d39:	00 00                	add    %al,(%rax)
 d3b:	00 1c 00             	add    %bl,(%rax,%rax,1)
 d3e:	00 00                	add    %al,(%rax)
 d40:	60                   	(bad)  
 d41:	fa                   	cli    
 d42:	ff                   	(bad)  
 d43:	ff 2b                	ljmp   *(%rbx)
	...
 d4d:	00 00                	add    %al,(%rax)
 d4f:	00 14 00             	add    %dl,(%rax,%rax,1)
 d52:	00 00                	add    %al,(%rax)
 d54:	00 00                	add    %al,(%rax)
 d56:	00 00                	add    %al,(%rax)
 d58:	01 7a 52             	add    %edi,0x52(%rdx)
 d5b:	00 01                	add    %al,(%rcx)
 d5d:	78 10                	js     d6f <__GNU_EH_FRAME_HDR+0x93>
 d5f:	01 1b                	add    %ebx,(%rbx)
 d61:	0c 07                	or     $0x7,%al
 d63:	08 90 01 00 00 24    	or     %dl,0x24000001(%rax)
 d69:	00 00                	add    %al,(%rax)
 d6b:	00 1c 00             	add    %bl,(%rax,%rax,1)
 d6e:	00 00                	add    %al,(%rax)
 d70:	80 f9 ff             	cmp    $0xff,%cl
 d73:	ff a0 00 00 00 00    	jmpq   *0x0(%rax)
 d79:	0e                   	(bad)  
 d7a:	10 46 0e             	adc    %al,0xe(%rsi)
 d7d:	18 4a 0f             	sbb    %cl,0xf(%rdx)
 d80:	0b 77 08             	or     0x8(%rdi),%esi
 d83:	80 00 3f             	addb   $0x3f,(%rax)
 d86:	1a 3b                	sbb    (%rbx),%bh
 d88:	2a 33                	sub    (%rbx),%dh
 d8a:	24 22                	and    $0x22,%al
 d8c:	00 00                	add    %al,(%rax)
 d8e:	00 00                	add    %al,(%rax)
 d90:	14 00                	adc    $0x0,%al
 d92:	00 00                	add    %al,(%rax)
 d94:	44 00 00             	add    %r8b,(%rax)
 d97:	00 f8                	add    %bh,%al
 d99:	f9                   	stc    
 d9a:	ff                   	(bad)  
 d9b:	ff 08                	decl   (%rax)
	...
 da5:	00 00                	add    %al,(%rax)
 da7:	00 18                	add    %bl,(%rax)
 da9:	00 00                	add    %al,(%rax)
 dab:	00 5c 00 00          	add    %bl,0x0(%rax,%rax,1)
 daf:	00 fa                	add    %bh,%dl
 db1:	fa                   	cli    
 db2:	ff                   	(bad)  
 db3:	ff 36                	pushq  (%rsi)
 db5:	00 00                	add    %al,(%rax)
 db7:	00 00                	add    %al,(%rax)
 db9:	41 0e                	rex.B (bad) 
 dbb:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
 dc1:	00 00                	add    %al,(%rax)
 dc3:	00 20                	add    %ah,(%rax)
 dc5:	00 00                	add    %al,(%rax)
 dc7:	00 78 00             	add    %bh,0x0(%rax)
 dca:	00 00                	add    %al,(%rax)
 dcc:	14 fb                	adc    $0xfb,%al
 dce:	ff                   	(bad)  
 dcf:	ff 10                	callq  *(%rax)
 dd1:	03 00                	add    (%rax),%eax
 dd3:	00 00                	add    %al,(%rax)
 dd5:	41 0e                	rex.B (bad) 
 dd7:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
 ddd:	48 83 03 03          	addq   $0x3,(%rbx)
 de1:	03 03                	add    (%rbx),%eax
 de3:	0c 07                	or     $0x7,%al
 de5:	08 00                	or     %al,(%rax)
 de7:	00 44 00 00          	add    %al,0x0(%rax,%rax,1)
 deb:	00 9c 00 00 00 00 fe 	add    %bl,-0x2000000(%rax,%rax,1)
 df2:	ff                   	(bad)  
 df3:	ff 65 00             	jmpq   *0x0(%rbp)
 df6:	00 00                	add    %al,(%rax)
 df8:	00 42 0e             	add    %al,0xe(%rdx)
 dfb:	10 8f 02 42 0e 18    	adc    %cl,0x180e4202(%rdi)
 e01:	8e 03                	mov    (%rbx),%es
 e03:	45 0e                	rex.RB (bad) 
 e05:	20 8d 04 42 0e 28    	and    %cl,0x280e4204(%rbp)
 e0b:	8c 05 48 0e 30 86    	mov    %es,-0x79cff1b8(%rip)        # ffffffff86301c59 <_end+0xffffffff860ffc41>
 e11:	06                   	(bad)  
 e12:	48 0e                	rex.W (bad) 
 e14:	38 83 07 4d 0e 40    	cmp    %al,0x400e4d07(%rbx)
 e1a:	72 0e                	jb     e2a <__GNU_EH_FRAME_HDR+0x14e>
 e1c:	38 41 0e             	cmp    %al,0xe(%rcx)
 e1f:	30 41 0e             	xor    %al,0xe(%rcx)
 e22:	28 42 0e             	sub    %al,0xe(%rdx)
 e25:	20 42 0e             	and    %al,0xe(%rdx)
 e28:	18 42 0e             	sbb    %al,0xe(%rdx)
 e2b:	10 42 0e             	adc    %al,0xe(%rdx)
 e2e:	08 00                	or     %al,(%rax)
 e30:	10 00                	adc    %al,(%rax)
 e32:	00 00                	add    %al,(%rax)
 e34:	e4 00                	in     $0x0,%al
 e36:	00 00                	add    %al,(%rax)
 e38:	28 fe                	sub    %bh,%dh
 e3a:	ff                   	(bad)  
 e3b:	ff 02                	incl   (%rdx)
 e3d:	00 00                	add    %al,(%rax)
 e3f:	00 00                	add    %al,(%rax)
 e41:	00 00                	add    %al,(%rax)
	...

0000000000000e44 <__FRAME_END__>:
 e44:	00 00                	add    %al,(%rax)
	...

Disassemblamento della sezione .init_array:

0000000000201d78 <__frame_dummy_init_array_entry>:
  201d78:	a0                   	.byte 0xa0
  201d79:	08 00                	or     %al,(%rax)
  201d7b:	00 00                	add    %al,(%rax)
  201d7d:	00 00                	add    %al,(%rax)
	...

Disassemblamento della sezione .fini_array:

0000000000201d80 <__do_global_dtors_aux_fini_array_entry>:
  201d80:	60                   	(bad)  
  201d81:	08 00                	or     %al,(%rax)
  201d83:	00 00                	add    %al,(%rax)
  201d85:	00 00                	add    %al,(%rax)
	...

Disassemblamento della sezione .dynamic:

0000000000201d88 <_DYNAMIC>:
  201d88:	01 00                	add    %eax,(%rax)
  201d8a:	00 00                	add    %al,(%rax)
  201d8c:	00 00                	add    %al,(%rax)
  201d8e:	00 00                	add    %al,(%rax)
  201d90:	01 00                	add    %eax,(%rax)
  201d92:	00 00                	add    %al,(%rax)
  201d94:	00 00                	add    %al,(%rax)
  201d96:	00 00                	add    %al,(%rax)
  201d98:	0c 00                	or     $0x0,%al
  201d9a:	00 00                	add    %al,(%rax)
  201d9c:	00 00                	add    %al,(%rax)
  201d9e:	00 00                	add    %al,(%rax)
  201da0:	d8 06                	fadds  (%rsi)
  201da2:	00 00                	add    %al,(%rax)
  201da4:	00 00                	add    %al,(%rax)
  201da6:	00 00                	add    %al,(%rax)
  201da8:	0d 00 00 00 00       	or     $0x0,%eax
  201dad:	00 00                	add    %al,(%rax)
  201daf:	00 64 0c 00          	add    %ah,0x0(%rsp,%rcx,1)
  201db3:	00 00                	add    %al,(%rax)
  201db5:	00 00                	add    %al,(%rax)
  201db7:	00 19                	add    %bl,(%rcx)
  201db9:	00 00                	add    %al,(%rax)
  201dbb:	00 00                	add    %al,(%rax)
  201dbd:	00 00                	add    %al,(%rax)
  201dbf:	00 78 1d             	add    %bh,0x1d(%rax)
  201dc2:	20 00                	and    %al,(%rax)
  201dc4:	00 00                	add    %al,(%rax)
  201dc6:	00 00                	add    %al,(%rax)
  201dc8:	1b 00                	sbb    (%rax),%eax
  201dca:	00 00                	add    %al,(%rax)
  201dcc:	00 00                	add    %al,(%rax)
  201dce:	00 00                	add    %al,(%rax)
  201dd0:	08 00                	or     %al,(%rax)
  201dd2:	00 00                	add    %al,(%rax)
  201dd4:	00 00                	add    %al,(%rax)
  201dd6:	00 00                	add    %al,(%rax)
  201dd8:	1a 00                	sbb    (%rax),%al
  201dda:	00 00                	add    %al,(%rax)
  201ddc:	00 00                	add    %al,(%rax)
  201dde:	00 00                	add    %al,(%rax)
  201de0:	80 1d 20 00 00 00 00 	sbbb   $0x0,0x20(%rip)        # 201e07 <_DYNAMIC+0x7f>
  201de7:	00 1c 00             	add    %bl,(%rax,%rax,1)
  201dea:	00 00                	add    %al,(%rax)
  201dec:	00 00                	add    %al,(%rax)
  201dee:	00 00                	add    %al,(%rax)
  201df0:	08 00                	or     %al,(%rax)
  201df2:	00 00                	add    %al,(%rax)
  201df4:	00 00                	add    %al,(%rax)
  201df6:	00 00                	add    %al,(%rax)
  201df8:	f5                   	cmc    
  201df9:	fe                   	(bad)  
  201dfa:	ff 6f 00             	ljmp   *0x0(%rdi)
  201dfd:	00 00                	add    %al,(%rax)
  201dff:	00 98 02 00 00 00    	add    %bl,0x2(%rax)
  201e05:	00 00                	add    %al,(%rax)
  201e07:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 201e0d <_DYNAMIC+0x85>
  201e0d:	00 00                	add    %al,(%rax)
  201e0f:	00 20                	add    %ah,(%rax)
  201e11:	04 00                	add    $0x0,%al
  201e13:	00 00                	add    %al,(%rax)
  201e15:	00 00                	add    %al,(%rax)
  201e17:	00 06                	add    %al,(%rsi)
  201e19:	00 00                	add    %al,(%rax)
  201e1b:	00 00                	add    %al,(%rax)
  201e1d:	00 00                	add    %al,(%rax)
  201e1f:	00 b8 02 00 00 00    	add    %bh,0x2(%rax)
  201e25:	00 00                	add    %al,(%rax)
  201e27:	00 0a                	add    %cl,(%rdx)
  201e29:	00 00                	add    %al,(%rax)
  201e2b:	00 00                	add    %al,(%rax)
  201e2d:	00 00                	add    %al,(%rax)
  201e2f:	00 cb                	add    %cl,%bl
  201e31:	00 00                	add    %al,(%rax)
  201e33:	00 00                	add    %al,(%rax)
  201e35:	00 00                	add    %al,(%rax)
  201e37:	00 0b                	add    %cl,(%rbx)
  201e39:	00 00                	add    %al,(%rax)
  201e3b:	00 00                	add    %al,(%rax)
  201e3d:	00 00                	add    %al,(%rax)
  201e3f:	00 18                	add    %bl,(%rax)
  201e41:	00 00                	add    %al,(%rax)
  201e43:	00 00                	add    %al,(%rax)
  201e45:	00 00                	add    %al,(%rax)
  201e47:	00 15 00 00 00 00    	add    %dl,0x0(%rip)        # 201e4d <_DYNAMIC+0xc5>
	...
  201e55:	00 00                	add    %al,(%rax)
  201e57:	00 03                	add    %al,(%rbx)
  201e59:	00 00                	add    %al,(%rax)
  201e5b:	00 00                	add    %al,(%rax)
  201e5d:	00 00                	add    %al,(%rax)
  201e5f:	00 78 1f             	add    %bh,0x1f(%rax)
  201e62:	20 00                	and    %al,(%rax)
  201e64:	00 00                	add    %al,(%rax)
  201e66:	00 00                	add    %al,(%rax)
  201e68:	02 00                	add    (%rax),%al
  201e6a:	00 00                	add    %al,(%rax)
  201e6c:	00 00                	add    %al,(%rax)
  201e6e:	00 00                	add    %al,(%rax)
  201e70:	d8 00                	fadds  (%rax)
  201e72:	00 00                	add    %al,(%rax)
  201e74:	00 00                	add    %al,(%rax)
  201e76:	00 00                	add    %al,(%rax)
  201e78:	14 00                	adc    $0x0,%al
  201e7a:	00 00                	add    %al,(%rax)
  201e7c:	00 00                	add    %al,(%rax)
  201e7e:	00 00                	add    %al,(%rax)
  201e80:	07                   	(bad)  
  201e81:	00 00                	add    %al,(%rax)
  201e83:	00 00                	add    %al,(%rax)
  201e85:	00 00                	add    %al,(%rax)
  201e87:	00 17                	add    %dl,(%rdi)
	...
  201e91:	06                   	(bad)  
  201e92:	00 00                	add    %al,(%rax)
  201e94:	00 00                	add    %al,(%rax)
  201e96:	00 00                	add    %al,(%rax)
  201e98:	07                   	(bad)  
  201e99:	00 00                	add    %al,(%rax)
  201e9b:	00 00                	add    %al,(%rax)
  201e9d:	00 00                	add    %al,(%rax)
  201e9f:	00 40 05             	add    %al,0x5(%rax)
  201ea2:	00 00                	add    %al,(%rax)
  201ea4:	00 00                	add    %al,(%rax)
  201ea6:	00 00                	add    %al,(%rax)
  201ea8:	08 00                	or     %al,(%rax)
  201eaa:	00 00                	add    %al,(%rax)
  201eac:	00 00                	add    %al,(%rax)
  201eae:	00 00                	add    %al,(%rax)
  201eb0:	c0 00 00             	rolb   $0x0,(%rax)
  201eb3:	00 00                	add    %al,(%rax)
  201eb5:	00 00                	add    %al,(%rax)
  201eb7:	00 09                	add    %cl,(%rcx)
  201eb9:	00 00                	add    %al,(%rax)
  201ebb:	00 00                	add    %al,(%rax)
  201ebd:	00 00                	add    %al,(%rax)
  201ebf:	00 18                	add    %bl,(%rax)
  201ec1:	00 00                	add    %al,(%rax)
  201ec3:	00 00                	add    %al,(%rax)
  201ec5:	00 00                	add    %al,(%rax)
  201ec7:	00 1e                	add    %bl,(%rsi)
  201ec9:	00 00                	add    %al,(%rax)
  201ecb:	00 00                	add    %al,(%rax)
  201ecd:	00 00                	add    %al,(%rax)
  201ecf:	00 08                	add    %cl,(%rax)
  201ed1:	00 00                	add    %al,(%rax)
  201ed3:	00 00                	add    %al,(%rax)
  201ed5:	00 00                	add    %al,(%rax)
  201ed7:	00 fb                	add    %bh,%bl
  201ed9:	ff                   	(bad)  
  201eda:	ff 6f 00             	ljmp   *0x0(%rdi)
  201edd:	00 00                	add    %al,(%rax)
  201edf:	00 01                	add    %al,(%rcx)
  201ee1:	00 00                	add    %al,(%rax)
  201ee3:	08 00                	or     %al,(%rax)
  201ee5:	00 00                	add    %al,(%rax)
  201ee7:	00 fe                	add    %bh,%dh
  201ee9:	ff                   	(bad)  
  201eea:	ff 6f 00             	ljmp   *0x0(%rdi)
  201eed:	00 00                	add    %al,(%rax)
  201eef:	00 10                	add    %dl,(%rax)
  201ef1:	05 00 00 00 00       	add    $0x0,%eax
  201ef6:	00 00                	add    %al,(%rax)
  201ef8:	ff                   	(bad)  
  201ef9:	ff                   	(bad)  
  201efa:	ff 6f 00             	ljmp   *0x0(%rdi)
  201efd:	00 00                	add    %al,(%rax)
  201eff:	00 01                	add    %al,(%rcx)
  201f01:	00 00                	add    %al,(%rax)
  201f03:	00 00                	add    %al,(%rax)
  201f05:	00 00                	add    %al,(%rax)
  201f07:	00 f0                	add    %dh,%al
  201f09:	ff                   	(bad)  
  201f0a:	ff 6f 00             	ljmp   *0x0(%rdi)
  201f0d:	00 00                	add    %al,(%rax)
  201f0f:	00 ec                	add    %ch,%ah
  201f11:	04 00                	add    $0x0,%al
  201f13:	00 00                	add    %al,(%rax)
  201f15:	00 00                	add    %al,(%rax)
  201f17:	00 f9                	add    %bh,%cl
  201f19:	ff                   	(bad)  
  201f1a:	ff 6f 00             	ljmp   *0x0(%rdi)
  201f1d:	00 00                	add    %al,(%rax)
  201f1f:	00 03                	add    %al,(%rbx)
	...

Disassemblamento della sezione .got:

0000000000201f78 <_GLOBAL_OFFSET_TABLE_>:
  201f78:	88 1d 20 00 00 00    	mov    %bl,0x20(%rip)        # 201f9e <_GLOBAL_OFFSET_TABLE_+0x26>
	...
  201f8e:	00 00                	add    %al,(%rax)
  201f90:	06                   	(bad)  
  201f91:	07                   	(bad)  
  201f92:	00 00                	add    %al,(%rax)
  201f94:	00 00                	add    %al,(%rax)
  201f96:	00 00                	add    %al,(%rax)
  201f98:	16                   	(bad)  
  201f99:	07                   	(bad)  
  201f9a:	00 00                	add    %al,(%rax)
  201f9c:	00 00                	add    %al,(%rax)
  201f9e:	00 00                	add    %al,(%rax)
  201fa0:	26 07                	es (bad) 
  201fa2:	00 00                	add    %al,(%rax)
  201fa4:	00 00                	add    %al,(%rax)
  201fa6:	00 00                	add    %al,(%rax)
  201fa8:	36 07                	ss (bad) 
  201faa:	00 00                	add    %al,(%rax)
  201fac:	00 00                	add    %al,(%rax)
  201fae:	00 00                	add    %al,(%rax)
  201fb0:	46 07                	rex.RX (bad) 
  201fb2:	00 00                	add    %al,(%rax)
  201fb4:	00 00                	add    %al,(%rax)
  201fb6:	00 00                	add    %al,(%rax)
  201fb8:	56                   	push   %rsi
  201fb9:	07                   	(bad)  
  201fba:	00 00                	add    %al,(%rax)
  201fbc:	00 00                	add    %al,(%rax)
  201fbe:	00 00                	add    %al,(%rax)
  201fc0:	66 07                	data16 (bad) 
  201fc2:	00 00                	add    %al,(%rax)
  201fc4:	00 00                	add    %al,(%rax)
  201fc6:	00 00                	add    %al,(%rax)
  201fc8:	76 07                	jbe    201fd1 <_GLOBAL_OFFSET_TABLE_+0x59>
  201fca:	00 00                	add    %al,(%rax)
  201fcc:	00 00                	add    %al,(%rax)
  201fce:	00 00                	add    %al,(%rax)
  201fd0:	86 07                	xchg   %al,(%rdi)
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

0000000000202010 <__bss_start>:
	...

Disassemblamento della sezione .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 55 62             	sub    %dl,0x62(%rbp)
   8:	75 6e                	jne    78 <_init-0x660>
   a:	74 75                	je     81 <_init-0x657>
   c:	20 37                	and    %dh,(%rdi)
   e:	2e 33 2e             	xor    %cs:(%rsi),%ebp
  11:	30 2d 31 36 75 62    	xor    %ch,0x62753631(%rip)        # 62753648 <_end+0x62551630>
  17:	75 6e                	jne    87 <_init-0x651>
  19:	74 75                	je     90 <_init-0x648>
  1b:	33 29                	xor    (%rcx),%ebp
  1d:	20 37                	and    %dh,(%rdi)
  1f:	2e 33 2e             	xor    %cs:(%rsi),%ebp
  22:	30 00                	xor    %al,(%rax)
