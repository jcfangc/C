### ��д����ĺ�����
***
~~~
    void get_extension(const char *file_name, char *extension);
~~~
file_name ָ������ļ������ַ������������ļ�������չ�洢�� extension ָ����ַ����С����磬����ļ����� ��memo.txt������������ ��txt�� �洢�� extension ָ����ַ����С�����ļ���û����չ������������ extension ָ����ַ����д洢һ�����ַ���������һ�����ַ����ɣ����ں�����ʹ�� strlen ������ strcpy ������ʹ�価���ܼ򵥡�
***

<br>

�ο��𰸣�<br>
~~~
    void get_extension(const char *file_name, char *extension)
    {
        // ȷ���Ƿ������չ��
        while (*file_name != '.' && *file_name != '\0') {
            file_name++;
        }
        // ����չ��
        if ((*file_name == '\0') || (*file_name == '.' && *(file_name + 1) == '\0')) {
            *extension = '\0';
        }
        // ������չ��
        else {
            strcpy(extension, (file_name + 1));
        }
    }
~~~
���ﲢû���õ���Ŀ������ʹ�õ� strlen ������ͬʱҲ�Ǹ�����ȫ�ĺ�����strcpy ����ʹ��ʱ�п��ܸ�ֵ���ַ�������� extension ��ָ����ַ�����Ĵ�С��
~~~
    void get_extension(const char *file_name, char *extension)
    {
        // ��λ�� '.'
        for (; *file_name != '.'; file_name++) {
            if (*file_name == '\0') {
                *extension = '\0';
                return;
            }
        }

        // '.' ֮��ļ�Ϊ��չ��
        strcpy(extension, ++file_name);
    }
~~~
����һ����Ϊ��̵İ汾�������������ǲ���ȫ�ģ�����ͬ�ϡ���ϧ���ǣ������𰸶����ܺܺõ��к����⡣