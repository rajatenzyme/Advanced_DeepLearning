import os
os.environ["OPENAI_API_KEY"] = ""

import openai
from langchain.llms import OpenAI
import streamlit as st

#streamlit
st.title('Langchain Demo')
input_text =  st.text_input("Search any topic here")

# openai llms
llm = OpenAI(temperature = 0.8)


if input_text:
    st.write(llm(input_text))