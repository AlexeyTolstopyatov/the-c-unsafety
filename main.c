#include <stdio.h>
#include <stdlib.h>

//
// Система типов называется безопасной или надёжной,
// если в программах, прошедших проверку согласования типов,
// исключена возможность возникновения ошибок согласования
// типов во время выполнения.
//

//
// Неявные преобразования
// Implict Conversations
//
void impc(void);

//
// Ограничения массива
// Array Bounds
//
void arrayb(void);

//
// Указатели
// Pointers
//
void pointers(void);

//
// Перетипирование с помощью ссылки
// Links
//
void retyping(void);

int main() {
    retyping();
    return 0;
}

void implc(void) {
    // В C/++ типизация данных статическая, но не смотря на это
    // Вполне себе можно неявно привести одно в другое.
    //
    int i32max = 2147483647;
    short container = i32max;

    printf("Containment: %d", container);

    // Не знаю как GCC, но CLang остановил процесс сборки.
    // Такое допускать нельзя, но в теории С/++ такое до сборки допускает.
    //      "D:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" --build D:\Projects\c\safety\cmake-build-debug --target safety -j 6
    //      [1/2] Building C object CMakeFiles/safety.dir/main.c.obj
    //      [2/2] Linking C executable safety.exe
    //      FAILED: safety.exe
    //      cmd.exe /C "cd . && "D:\Program Files\JetBrains\CLion 2023.1.4\bin\mingw\bin\gcc.exe" -g  CMakeFiles/safety.dir/main.c.obj -o safety.exe -Wl,--out-implib,libsafety.dll.a -Wl,--major-image-version,0,--minor-image-version,0  -lkernel32 -luser32 -lgdi32 -lwinspool -lshell32 -lole32 -loleaut32 -luuid -lcomdlg32 -ladvapi32 && cd ."
    //      D:\Program Files\JetBrains\CLion 2023.1.4\bin\mingw\bin/ld.exe: CMakeFiles/safety.dir/main.c.obj: in function `main':
    //      D:/Projects/c/safety/main.c:14: undefined reference to `impc'
    //      collect2.exe: error: ld returned 1 exit status
    //      ninja: build stopped: subcommand failed.
    //
}
void arrayb(void) {
    // Доказательство отсутствия типобезопасности, как мне кажется
    // для C/++ это скорее ситуация с массивами данных.

    // Выход за границу массива — это частный случай переполнения буфера.
    //
    // Ошибка возникает, если индекс,
    // с помощью которого обращаются к элементам массива,
    // превышает допустимое значение.
    // При этом идёт обращение за границы массива,
    // что является неопределённым поведением.

    // Предположим:
    int * buffer = malloc(100);
    int i = 0;
    while (i <= 100)
    {
        buffer[i] = '68' + i;
        printf("buffer[%d] = %d\n", i, buffer[i]);
        i++;
    }
    free(buffer);

    // buffer[0] = 13880
    // buffer[1] = 13881
    // buffer[2] = 13882
    // buffer[3] = 13883
    // buffer[4] = 13884
    // buffer[5] = 13885
    // buffer[6] = 13886
    // buffer[7] = 13887
    // buffer[8] = 13888
    // buffer[9] = 13889
    // buffer[10] = 13890
    // buffer[11] = 13891
    // buffer[12] = 13892
    // buffer[13] = 13893
    // buffer[14] = 13894
    // buffer[15] = 13895
    // buffer[16] = 13896
    // buffer[17] = 13897
    // buffer[18] = 13898
    // buffer[19] = 13899
    // buffer[20] = 13900
    // buffer[21] = 13901
    // buffer[22] = 13902
    // buffer[23] = 13903
    // buffer[24] = 13904
    // buffer[25] = 13905
    // buffer[26] = 13906
    // buffer[27] = 13907
    // buffer[28] = 13908
    // buffer[29] = 13909
    // buffer[30] = 13910
    // buffer[31] = 13911
    // buffer[32] = 13912
    // buffer[33] = 13913
    // buffer[34] = 13914
    // buffer[35] = 13915
    // buffer[36] = 13916
    // buffer[37] = 13917
    // buffer[38] = 13918
    // buffer[39] = 13919
    // buffer[40] = 13920
    // buffer[41] = 13921
    // buffer[42] = 13922
    // buffer[43] = 13923
    // buffer[44] = 13924
    // buffer[45] = 13925
    // buffer[46] = 13926
    // buffer[47] = 13927
    // buffer[48] = 13928
    // buffer[49] = 13929
    // buffer[50] = 13930
    // buffer[51] = 13931
    // buffer[52] = 13932
    // buffer[53] = 13933
    // buffer[54] = 13934
    // buffer[55] = 13935
    // buffer[56] = 13936
    // buffer[57] = 13937
    // buffer[58] = 13938
    // buffer[59] = 13939
    // buffer[60] = 13940
    // buffer[61] = 13941
    // buffer[62] = 13942
    // buffer[63] = 13943
    // buffer[64] = 13944
    // buffer[65] = 13945
    // buffer[66] = 13946
    // buffer[67] = 13947
    // buffer[68] = 13948
    // buffer[69] = 13949
    // buffer[70] = 13950
    // buffer[71] = 13951
    // buffer[72] = 13952
    // buffer[73] = 13953
    // buffer[74] = 13954
    // buffer[75] = 13955
    // buffer[76] = 13956
    // buffer[77] = 13957
    // buffer[78] = 13958
    // buffer[79] = 13959
    // buffer[80] = 13960
    // buffer[81] = 13961
    // buffer[82] = 13962
    // buffer[83] = 13963
    // buffer[84] = 13964
    // buffer[85] = 13965
    // buffer[86] = 13966
    // buffer[87] = 13967
    // buffer[88] = 13968
    // buffer[89] = 13969
    // buffer[90] = 13970
    // buffer[91] = 13971
    // buffer[92] = 13972
    // buffer[93] = 13973
    // buffer[94] = 13974
    // buffer[95] = 13975
    // buffer[96] = 13976
    // buffer[97] = 13977
    // buffer[98] = 13978
    // buffer[99] = 13979
    // buffer[100] = 13980
    //
    // Process finished with exit code -1073740940 (0xC0000374)

    // В языках программирования С и С++ нет строгого контроля
    // выхода за границы массива.
}
void pointers(void) {
    // Опасность Неинициализированных указателей.
    // Функция присваивает значение 10 некоторому неизвестному участку памяти.
    // Указатель р_segment не получал адреса памяти, которую можно использовать.
    // Следовательно, он содержит неопределенное значение.
    //
    // Очень много думал над этим, но похоже, когда программа невелика,
    // р_segment, скорее всего, содержит «безопасный» адрес,
    // не принадлежащий коду, данным, стеку, куче или ОС.
    // Но факт возможности такой ситуации субъективно страшно.

    int segment;
    int *p_segment;

    segment = 10;
    *p_segment = segment;

    printf("p_segment=0x&x\n*p_segment=%s\n", p_segment, *p_segment);
    //
    // Process finished with exit code -1073741819 (0xC0000005)

}
void retyping() {
    int buffer[6];
    void * p_buffer = &buffer;
    p_buffer = "BRUH";

    printf("%s", p_buffer);
}