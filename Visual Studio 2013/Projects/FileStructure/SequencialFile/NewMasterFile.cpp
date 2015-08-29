#include "NewMasterFile.h"
#include "FileWriteException.h"
#include "FindKey.h"
#include "AscendingSorting.h"

//트랜잭션 파일을 전달 받는다
NewMasterFile::NewMasterFile(TransactionFile t) {
	rec = t.getRecordVector();

	//트랜잭션 파일의 끝을 알기위해
	//키값이 -1인 레코드를 마지막에 추가한다
	rec.push_back(Record(-1));
}
void NewMasterFile::createNewMasterFile() {
	ifstream in;
	int oldKey;

	//구 마스터 파일을 읽어온다
	readOldMasterFile();

	in.open("oldmaster.txt");

	in >> oldKey;
	cout << "출력 4(Exception Code)" << endl;
	//트랜잭션 파일의 시작과 끝까지 반복한다
	for (Iterator iter = rec.begin(); iter < rec.end() - 1;) {
		try {
			//트랜잭션 키값이 구 마스터 키값보다 작거나 같으면
			while ((*iter).getKey() <= oldKey) {
				//삽입
				if ((*iter).getUpdateCode() == 'i') {
					//삽입하기 전에 존재여부를 확인
					Iterator findIter = findKey((*iter).getKey());

					//같은 키값이 존재하는 경우 예외를 출력
					if (findIter != resultRec.end())
						throw new FileWriteException((*iter).getKey(), (*iter).getUpdateCode());
					else {
						//없을 경우 삽입을 진행하고 다음 트랜잭션 레코드를 읽어 온다
						resultRec.push_back(Record((*iter).getKey()));
						iter++;
					}
				}
				//삭제
				else if ((*iter).getUpdateCode() == 'd') {
					//삭제하기 전에 존재여부를 확인
					Iterator findIter = findKey((*iter).getKey());

					//키값이 존재하면 삭제를 진행
					if (findIter != resultRec.end()) {
						resultRec.erase(findIter);
						iter++;
					}
					else
						//없으면 예외를 출력
						throw new FileWriteException((*iter).getKey(), (*iter).getUpdateCode());
				}
				//수정
				else if ((*iter).getUpdateCode() == 'm') {
					//수정하기 전에 존재여부를 확인
					Iterator findIter = findKey((*iter).getKey());

					//키값이 존재하면 수정을 진행
					if (findIter != resultRec.end()) {
						(*findIter).setKey((*iter).getKey());
						iter++;
					}
					else
						//없으면 예외를 출력
						throw new FileWriteException((*iter).getKey(), (*iter).getUpdateCode());
				}
				//트랜잭션 키값이 -1인 경우는 트랜잭션 파일의 끝이다
				if ((*iter).getKey() == -1)
					break;
			}
			//다음 구 마스터 키값을 읽어온다
			in >> oldKey;
		}
		catch (FileWriteException* e) {
			//다음 트랜잭션 레코드를 읽어오고 예외 메시지를 출력한다
			iter++;
			e->printExceptionMasseng();
		}
	}
	in.close();
}
Iterator NewMasterFile::findKey(int key) {
	//같은 키값이 존재하면 해당 주소값을 반환 없으면 끝 주소값을 반환
	FindKey findkey;
	findkey.key = key;
	return find_if(resultRec.begin(), resultRec.end(), findkey);
}
void NewMasterFile::readOldMasterFile() {
	ifstream in;
	int oldKey;

	//구 마스터 파일을 신 마스터 파일에 복사한다
	//신 마스터 파일도 비교대상이 될 수 있다
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

	//완성된 신 마스터 파일을 정렬한다
	sort(resultRec.begin(), resultRec.end(), ascending);

	//완성된 신 마스터 파일을 파일에 기록하고 콘솔화면에 출력
	for (Iterator iter = resultRec.begin(); iter < resultRec.end(); iter++) {
		cout << (*iter).getKey() << endl;
		out << (*iter).getKey() << endl;
	}

	out.close();
}