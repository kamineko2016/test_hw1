pipeline {
    agent {
        docker {
            image 'gcc'
        }
    }
    stages {
        stage('Build') {
            steps {
                sh 'git submodule update --init --recursive'
                sh 'make'
            }
        }
        stage('Test') {
            steps {
                sh './hw1_Triangle_full'
		sh './hw1_NextDate_full'
		sh './hw1_Commission_full'
            }
        }
    }
}
