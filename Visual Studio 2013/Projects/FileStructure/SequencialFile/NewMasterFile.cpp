#include "NewMasterFile.h"
#include "FileWriteException.h"
#include "FindKey.h"
#include "AscendingSorting.h"

//Ʈ����� ������ ���� �޴´�
NewMasterFile::NewMasterFile(TransactionFile t) {
	rec = t.getRecordVector();

	//Ʈ����� ������ ���� �˱�����
	//Ű���� -1�� ���ڵ带 �������� �߰��Ѵ�
	rec.push_back(Record(-1));
}
void NewMasterFile::createNewMasterFile() {
	ifstream in;
	int oldKey;

	//�� ������ ������ �о�´�
	readOldMasterFile();

	in.open("oldmaster.txt");

	in >> oldKey;
	cout << "��� 4(Exception Code)" << endl;
	//Ʈ����� ������ ���۰� ������ �ݺ��Ѵ�
	for (Iterator iter = rec.begin(); iter < rec.end() - 1;) {
		try {
			//Ʈ����� Ű���� �� ������ Ű������ �۰ų� ������
			while ((*iter).getKey() <= oldKey) {
				//����
				if ((*iter).getUpdateCode() == 'i') {
					//�����ϱ� ���� ���翩�θ� Ȯ��
					Iterator findIter = findKey((*iter).getKey());

					//���� Ű���� �����ϴ� ��� ���ܸ� ���
					if (findIter != resultRec.end())
						throw new FileWriteException((*iter).getKey(), (*iter).getUpdateCode());
					else {
						//���� ��� ������ �����ϰ� ���� Ʈ����� ���ڵ带 �о� �´�
						resultRec.push_back(Record((*iter).getKey()));
						iter++;
					}
				}
				//����
				else if ((*iter).getUpdateCode() == 'd') {
					//�����ϱ� ���� ���翩�θ� Ȯ��
					Iterator findIter = findKey((*iter).getKey());

					//Ű���� �����ϸ� ������ ����
					if (findIter != resultRec.end()) {
						resultRec.erase(findIter);
						iter++;
					}
					else
						//������ ���ܸ� ���
						throw new FileWriteException((*iter).getKey(), (*iter).getUpdateCode());
				}
				//����
				else if ((*iter).getUpdateCode() == 'm') {
					//�����ϱ� ���� ���翩�θ� Ȯ��
					Iterator findIter = findKey((*iter).getKey());

					//Ű���� �����ϸ� ������ ����
					if (findIter != resultRec.end()) {
						(*findIter).setKey((*iter).getKey());
						iter++;
					}
					else
						//������ ���ܸ� ���
						throw new FileWriteException((*iter).getKey(), (*iter).getUpdateCode());
				}
				//Ʈ����� Ű���� -1�� ���� Ʈ����� ������ ���̴�
				if ((*iter).getKey() == -1)
					break;
			}
			//���� �� ������ Ű���� �о�´�
			in >> oldKey;
		}
		catch (FileWriteException* e) {
			//���� Ʈ����� ���ڵ带 �о���� ���� �޽����� ����Ѵ�
			iter++;
			e->printExceptionMasseng();
		}
	}
	in.close();
}
Iterator NewMasterFile::findKey(int key) {
	//���� Ű���� �����ϸ� �ش� �ּҰ��� ��ȯ ������ �� �ּҰ��� ��ȯ
	FindKey findkey;
	findkey.key = key;
	return find_if(resultRec.begin(), resultRec.end(), findkey);
}
void NewMasterFile::readOldMasterFile() {
	ifstream in;
	int oldKey;

	//�� ������ ������ �� ������ ���Ͽ� �����Ѵ�
	//�� ������ ���ϵ� �񱳴���� �� �� �ִ�
	in.open("oldmaster.txt");
	for (; !in.eof();) {
		in >> oldKey;
		resultRec.push_back(Record(oldKey));
	}
	in.close();
}
void NewMasterFile::printNewMasterFile() {
	ofstream out;
	AscendingSorting ascending;

	out.open("newmaster.txt");

	//�ϼ��� �� ������ ������ �����Ѵ�
	sort(resultRec.begin(), resultRec.end(), ascending);

	//�ϼ��� �� ������ ������ ���Ͽ� ����ϰ� �ܼ�ȭ�鿡 ���
	for (Iterator iter = resultRec.begin(); iter < resultRec.end(); iter++) {
		cout << (*iter).getKey() << endl;
		out << (*iter).getKey() << endl;
	}

	out.close();
}