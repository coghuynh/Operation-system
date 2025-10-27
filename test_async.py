import asyncio
import functools
import os
from openai import OpenAI

os.environ["OPENAI"] = "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"


async def call_open(client: OpenAI):
    resp = client.responses.create(
        model="gpt-3.5-turbo",
        input="Write a one-sentence bedtime story about a unicorn."
    )
    return resp

def non_async_call_open(client: OpenAI):
    resp = client.responses.create(
        model="gpt-3.5-turbo",
        input="Write a one-sentence bedtime story about a unicorn."
    )
    return resp

def test_nonasync(client):
    for _ in range(3):
        non_async_call_open(client)
        
async def test_async(client):
    await asyncio.gather(call_open(client), call_open(client), call_open(client))

if __name__ == "__main__":
    
    
    import time
    
    client = OpenAI(api_key=os.environ["OPENAI"])
    
    
    
    start = time.perf_counter()
    
    # test_nonasync(client)
    asyncio.run(test_async(client))
    
    duration = time.perf_counter() - start
    
    print(f"Time: {duration}")
    
    
    
    