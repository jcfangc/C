// 假定程序需要用英语/法语或西班牙语显示消息。使用条件编译编写程序片段，根据指定的宏是否定义来显示下列 3 条消息中的一条。
// Insert Disk 1 （如果定义了 ENGLISH）
// Inserez Le Disque 1 （如果定义了 FRENCH）
// Inerte El Disco 1 （如果定义了 SPANISH）

#if defined(ENGLISH)
Insert Disk 1
#elif defined(FRENCH)
Inserez Le Disque 1
#elif defined(SPANISH)
Inerte El Disco 1
#endif