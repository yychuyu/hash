// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� HASH_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// HASH_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef HASH_EXPORTS
#define HASH_API __declspec(dllexport)
#else
#define HASH_API __declspec(dllimport)
#endif

// �����Ǵ� hash.dll ������
class HASH_API Chash {
public:
	Chash(void);
	// TODO: �ڴ�������ķ�����
};

extern HASH_API int nhash;

HASH_API int fnhash(void);
